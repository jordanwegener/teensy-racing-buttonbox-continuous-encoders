// Teensy LC Button Box

#include <Encoder.h>

Encoder rotary1(2, 3);
Encoder rotary2(5, 6);
Encoder rotary3(8, 9);
Encoder rotary4(11, 12);

unsigned long rot1old, rot2old, rot3old, rot4old;
unsigned long rot1, rot2, rot3, rot4;
const long rot_delay = 70;             // stores delay between rotary clicks registering (so that windows registers them properly)
unsigned long previousMillis = 0;       // will store last time rotaries were updated

void setup()
{
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);

  rotary1.write(999999);
  rotary2.write(999999);
  rotary3.write(999999);
  rotary4.write(999999);

  rot1old = 999999;
  rot2old = 999999;
  rot3old = 999999;
  rot4old = 999999;

  Joystick.useManualSend(true);
}

void loop()
{
  // read the digital inputs and set the buttons

  // ignition, start and pushbuttons
  Joystick.button(1, !digitalRead(14));
  Joystick.button(2, !digitalRead(15));
  Joystick.button(3, !digitalRead(20));
  Joystick.button(4, !digitalRead(21));
  Joystick.button(5, !digitalRead(22));

  // rotary encoder push buttons
  Joystick.button(8, !digitalRead(4));
  Joystick.button(11, !digitalRead(7));
  Joystick.button(14, !digitalRead(10));
  Joystick.button(17, !digitalRead(13));

  // rotary encoder rotation

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= rot_delay) {

    previousMillis = currentMillis;
    
    rot1 = rotary1.read();
    rot2 = rotary2.read();
    rot3 = rotary3.read();
    rot4 = rotary4.read();
  
    // rotary 1
    if (rot1 <= rot1old - 2)
    {
      Serial.println(rotary1.read());
      Joystick.button(6, true);
      Joystick.button(7, false);
      Serial.println("Click up");
      Joystick.send_now();
      delay(50);
      rot1old = rotary1.read();
    }
    else if (rot1 >= rot1old + 2)
    {
      Serial.println(rotary1.read());
      Joystick.button(6, false);
      Joystick.button(7, true);
      Serial.println("Click down");
      Joystick.send_now();
      delay(50);
      rot1old = rotary1.read();
    }
    else
    {
      Serial.println(rotary1.read());
      Joystick.button(6, false);
      Joystick.button(7, false);
      Joystick.send_now();
    }
  
       // rotary 2
       if (rot2 < -1)
    {
      Joystick.button(9, true);
      Joystick.button(10, false);
      rotary2.write(0);
      Joystick.send_now();
    }
    else if (rot2 > 1)
    {
      Joystick.button(9, false);
      Joystick.button(10, true);
      rotary2.write(0);
      Joystick.send_now();
    }
    else
    {
      Joystick.button(9, false);
      Joystick.button(10, false);
      Joystick.send_now();
    }
  
    // rotary 3
    if (rot3 > -1)
    {
      Joystick.button(12, true);
      Joystick.button(13, false);
      rotary3.write(0);
      Joystick.send_now();
    }
    else if (rot3 < 1)
    {
      Joystick.button(12, false);
      Joystick.button(13, true);
      rotary3.write(0);
      Joystick.send_now();
    }
    else
    {
      Joystick.button(12, false);
      Joystick.button(13, false);
      Joystick.send_now();
    }
  
    // rotary 4
    if (rot4 > 1)
    {
      Joystick.button(15, true);
      Joystick.button(16, false);
      rotary4.write(0);
      Joystick.send_now();
    }
    else if (rot4 < -1)
    {
      Joystick.button(15, false);
      Joystick.button(16, true);
      rotary4.write(0);
    }
    else
    {
      Joystick.button(15, false);
      Joystick.button(16, false);
      Joystick.send_now();
    }
  }

  Joystick.send_now();
}
