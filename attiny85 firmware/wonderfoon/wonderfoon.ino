/* code written for ATTiny85
 * Tested only for internal oscillator at 1MHz
 * Arduino as ISP
 * by Floriaan Post
 */

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "Phone.h"

// uncomment this if you have an old version
// #define OLD_PIN_CONFIG

// debug on or off
#define DEBUG true

// pin config on attiny85
#define PIN_LED 0
#define PIN_PHONE A3
#define PIN_BUSY 4
#define TX 2
#define RX 1

#ifdef OLD_PIN_CONFIG
#define PIN_LED 0
#define PIN_PHONE A1
#define PIN_BUSY 1
#define TX 3
#define RX 4
#endif

// dial done when no new numbers detected after this timeout
#define LONG_TIMEOUT 2500

// service sound files (in 01/ folder)
#define DIAL_TONE 1
#define DISCONNECTED_TONE 2
#define WRONG_NUMBER_TONE 3
#define EMERGENCY_TRACK 4

// error codes (only used for debugging)
#define ERROR_DFPLAYER_INIT 1
#define ERROR_FILE_COUNT 2
#define ERROR_SERVICE_FILE_COUNT 3

int songCount;
int phoneState;
int playerState;
unsigned long timeOfLastInput = 0;
unsigned long lastPoll = 0;
String number = "";
bool isPlayingSong = false;
bool isWaitingForHook = false;


SoftwareSerial mp3Serial(RX, TX);
DFRobotDFPlayerMini mp3Player;
Phone phone(PIN_PHONE, DEBUG);

void(* resetFunc) (void) = 0; //declare reset function @ address 0

void blink() {
  digitalWrite(PIN_LED, HIGH);
  delay(300);
  digitalWrite(PIN_LED, LOW);
  delay(300);
}


void error(int code) {
  if (DEBUG) {  
    // blink error code and reset after!
    for (int i = 0; i < code; i++) {
      blink();
    }
    delay(1000);
  }
  resetFunc();
}

void numberCalled(String number) {
  isPlayingSong = true;
  
  if (number == "112" || number == "0611" || number == "911") {
    mp3Player.play(EMERGENCY_TRACK);
  } else {
    // loop if song is number > songCount (unsigned int is probably not long enough to store number, but that's not really a problem as long as the same number is called every time)
    unsigned int calledNumber = (number.toInt() - 1) % songCount + 1;
    if (calledNumber > 0) {
      mp3Player.playMp3Folder(calledNumber);
    } else {
      isPlayingSong = false;
      isWaitingForHook = true;
      mp3Player.loop(WRONG_NUMBER_TONE);
    }
  }
  // wait until song actually starts playing!
  delay(300);
}


void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUSY, INPUT);
  mp3Serial.begin(9600);
  
  // give the dfplayer some time to start up, if still failed to start up, give error code and try again
  delay(700);
  if (!mp3Player.begin(mp3Serial)) {
    error(ERROR_DFPLAYER_INIT);
  }
  delay(200);

  mp3Player.volume(30);  //Set volume value. From 0 to 30


  // find the file count -> if fail, give error code, restart and try again
  int totFileCount = -1;
  int tryCountTot = 0;
  while (totFileCount == -1 && tryCountTot < 10) {
   delay(200);
   totFileCount = mp3Player.readFileCounts();
   tryCountTot++;
  }
  if (totFileCount == -1) {
    error(ERROR_FILE_COUNT);
  }

  // find the service file count -> if fail, give error code, restart and try again
  int serviceFileCount = -1;
  int tryCountService = 0;
  while (serviceFileCount == -1 && tryCountService < 10) {
   delay(200);
   serviceFileCount = mp3Player.readFileCountsInFolder(1);
   tryCountService++;
  }
  if (serviceFileCount == -1) {
    error(ERROR_SERVICE_FILE_COUNT);
  }
  
  delay(200);

  // use only the files in the mp3 folder
  songCount = totFileCount - serviceFileCount;

//  mp3Player.playMp3Folder(3);

}

void loop() {
  
  phoneState = phone.readState();
  
  if (phoneState == NUMBER_DIALED && !isPlayingSong && !isWaitingForHook) {
    char dialedNumber = phone.getNumber() + '0';
    number += dialedNumber;
    timeOfLastInput = millis();
  }
  
  if (phoneState == ON_HOOK) {
    // reset everything
    isPlayingSong = false;
    isWaitingForHook = false;
    timeOfLastInput = 0;
    number = "";
    mp3Player.stop();    
  }
  
  if (phoneState == DIALING && !isPlayingSong && !isWaitingForHook) {
    // reset everything
    timeOfLastInput = millis();
    isPlayingSong = false;
    isWaitingForHook = false;
    mp3Player.stop();
  }

  if (phoneState == OFF_HOOK) {
    // reset everything to be sure to start clean
    isPlayingSong = false;
    isWaitingForHook = false;
    timeOfLastInput = 0;
    number = "";
    mp3Player.loop(DIAL_TONE);
  }

  if (timeOfLastInput && millis() - timeOfLastInput > LONG_TIMEOUT && !isPlayingSong && !isWaitingForHook) {
    timeOfLastInput = 0;
    numberCalled(number);
    number = "";
  }

  if (isPlayingSong && digitalRead(PIN_BUSY) == HIGH) {
    // song is done, play disconnected sound!
    isPlayingSong = false;
    isWaitingForHook = true;
    mp3Player.loop(DISCONNECTED_TONE);
  }
}
