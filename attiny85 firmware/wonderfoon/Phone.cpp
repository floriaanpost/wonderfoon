#include "Phone.h"

Phone::Phone(int pinPhone, bool debug = false) {
  _pinPhone = pinPhone;
  _debug = debug;
  _previousTime = millis();
}

char Phone::getNumber() {
  return _lastNumber;
}

int Phone::readState() {
  _phoneState = NO_CHANGE;
  _lineVoltage = analogRead(_pinPhone);
  
  if (_lineVoltage <= OFF_HOOK_THRESHOLD && !_lineLow) {
    _lineLow = true;
    _previousTime = millis();
  } 
  
  if (_lineVoltage > OFF_HOOK_THRESHOLD && _lineLow) {
    _lineLow = false;
    _previousTime = millis();
  }

  // calculate the time that the state did not change
  _unchangedTime = millis() - _previousTime;

  if (_lineVoltage > OFF_HOOK_THRESHOLD && _isDialing && !_pulseState) {
    if (millis() - _timeOfPreviousPulse > 50) { 
      _pulseState = true;
      _pulseCount++;
      if (_debug) {
        digitalWrite(PIN_LED, HIGH);
      }
      delay(30);
      if (_debug) {
        digitalWrite(PIN_LED, LOW); 
      }
    }
  }

  if (_lineVoltage <= DIALING_THRESHOLD && _pulseState) {
    _pulseState = false;
  }

  if (_lineVoltage <= DIALING_THRESHOLD && !_isDialing) {
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
