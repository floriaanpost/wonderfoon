#include "Arduino.h"

#ifndef Phone_cpp
#define Phone_cpp

#define NO_CHANGE 0
#define ON_HOOK 1
#define OFF_HOOK 2
#define DIALING 3
#define NUMBER_DIALED 4

#define PIN_LED 0

#define OFF_HOOK_THRESHOLD 450
#define DIALING_THRESHOLD 130

#define TIMEOUT 150

class Phone {
  public:
    Phone(int pinPhone, bool debug = false);
    int readState();
    char getNumber();
    
  private:
    int _pinPhone;
    int _lineVoltage;
    char _lastNumber;
    int _phoneState = NO_CHANGE;
    unsigned long _previousTime;
    unsigned long _unchangedTime;
    unsigned long _timeOfPreviousPulse;
    bool _lineLow = false;
    bool _isOnHook = true;
    bool _isDialing = false;
    bool _pulseState = false;
    int _pulseCount = 0;
    bool _debug = false;
    
};

#endif
