#include <IRremote.h>

uint16_t sVendorCode = 0xCB75;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IrSender.begin(13, ENABLE_LED_FEEDBACK);



}

void loop() {
  // put your main code here, to run repeatedly:

  IrSender.sendKaseikyo(0x37B, 0x0, 0, sVendorCode);
 // delay(100);
 // IrSender.sendKaseikyo(0x377, 0x30003775, 0, sVendorCode);
  delay(1000);
}
