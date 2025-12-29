#include <Servo.h>
#include <IRremote.hpp>
int led = 3;
Servo servo;


void setup() {
  Serial.begin(9600); 
  IrReceiver.begin(2);
  pinMode(led, OUTPUT);


  servo.attach(4);

}

void loop() {
    if (IrReceiver.decode()) {
      uint16_t command = IrReceiver.decodedIRData.command;
      Serial.println(command, HEX);
      IrReceiver.resume();

    if (command == 16) {
      digitalWrite(led, HIGH);
      }
      else {
        digitalWrite(led, LOW); 
    
  }
    if (command == 4) {
      for (int pos = 0; pos <= 180; pos = pos + 5) {
        servo.write(pos);
   
      }
    }
    if (command == 6) {
      for (int pow = 180; pow >= 0; pow = pow - 5) {
        servo.write(pow);
        delay(15);
      }

    IrReceiver.resume();
    }
}
}