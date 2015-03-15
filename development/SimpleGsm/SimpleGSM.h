#ifndef _SimpleGSM_H
#define _SimpleGSM_H

#include "Arduino.h"

#include <SoftwareSerial.h>

class SimpleGSM : public SoftwareSerial
{
  public:
    SimpleGSM (const byte rxPin, const byte txPin, const byte powerPin);

    bool begin (const long baudRate, const byte numberOfRetries);

    bool disableEcho ();

    bool setSMSTextMode ();

    bool sendSMS (const String phoneNumber, const String message);

    bool missedCall (const String phoneNumber, const unsigned long ringingDuration);

    bool startCall (const String phoneNumber);

    bool callIsDialing ();

    bool callIsRinging ();

    void waitOnCallDialing ();

    void waitOnCallRinging (const unsigned long duration);

    bool hangCall ();

  private:
    void restart ();

    bool setEcho (const bool state);

    bool setSMSMode (const byte mode);

    void queryForCallStatus ();

    bool responseIsReceived (char * const pattern, const long timeOut);

    static char * OK_RESPONSE_FORMAT;

    byte _powerPin;
};

#endif /* _SimpleGSM_H */