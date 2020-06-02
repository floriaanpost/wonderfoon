#include "Phone.h"

void Phone::setup(int pinPhone) {
  _pinPhone = pinPhone;
  _previousTime = millis();
}

char Phone::getNumber() {
  return _lastNumber;
}

int Phone::readState() {
  _phoneState = NO_CHANGE;
  _lineVoltage = analogRead(_pinPhone);
  
  if (_lineVoltage <= OFF_HOOK_AVG_THRESHOLD && !_lineLow) {
    _lineLow = true;
    _previousTime = millis();
  } else if (_lineVoltage > OFF_HOOK_AVG_THRESHOLD && _lineLow) {
    // on hook or pulse!
    _lineLow = false;
    _previousTime = millis();
    if (_isDialing ) {
      // make sure there is sufficient time between two pulses
      if (_previousTime - _timeOfPreviousPulse > 2) {
        _pulseCount++;
        _timeOfPreviousPulse = _previousTime;
      }
    }
  }

  // calculate the time that the state did not change
  _unchangedTime = millis() - _previousTime;

//  if (_isDialing && _unchangedTime >= 1 && !_lineLow) {
//    _pulseCount++;
//  }


  if (_lineVoltage <= DIALING_AVG_THRESHOLD && !_isDialing) {
    _pulseCount = 0;
    _isDialing = true;
    _phoneState = DIALING;
  }

  // line high for a "long" time, phone is on hook!
  if (_unchangedTime > TIMEOUT && !_lineLow && !_isOnHook) {
    _isOnHook = true;
    _isDialing = false;
    _pulseCount = 0;
    _phoneState = ON_HOOK;
  }

  if (_unchangedTime > TIMEOUT && _lineLow && _isOnHook) {
    _isOnHook = false;
    _isDialing = false;
    _pulseCount = 0;
    _phoneState = OFF_HOOK;
  }

  // line low for some time and pulses have been counted!
  if (_unchangedTime > TIMEOUT && _lineLow && _pulseCount > 0) {
    _lastNumber = _pulseCount >= 10 ? 0 : _pulseCount;
    _pulseCount = 0;
    _isDialing = false;
    _phoneState = NUMBER_DIALED;
  }

  return _phoneState;
}
