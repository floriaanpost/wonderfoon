#include "Arduino.h"

#ifndef Phone_cpp
#define Phone_cpp

#define NO_CHANGE 0
#define ON_HOOK 1
#define OFF_HOOK 2
#define DIALING 3
#define NUMBER_DIALED 4

#define OFF_HOOK_AVG_THRESHOLD 461
#define DIALING_AVG_THRESHOLD 217

#define TIMEOUT 150

class Phone {
  public:
    void setup(int pinPhone);
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
    int _pulseCount = 0;
    
};

#endif
