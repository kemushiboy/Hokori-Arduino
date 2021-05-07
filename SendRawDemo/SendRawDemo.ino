/*
 * SendRawDemo.cpp - demonstrates sending IR codes with sendRaw
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off.
 * Hex Value: 0x20DF10EF, 32 bits
 *
 * It is more efficient to use the sendNEC function to send NEC signals.
 * Use of sendRaw here, serves only as an example of using the function.
 *
 *  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
 *
 ************************************************************************************
 * MIT License
 *
 * Copyright (c) 2020-2021 Armin Joachimsmeyer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ************************************************************************************
 */
#include <Arduino.h>

/*
 * Define macros for input and output pin etc.
 */
#include "PinDefinitionsAndMore.h"

#include <IRremote.h>

const uint16_t IdZeroSignal[] = {3430,1570, 530,1120, 530,320, 530,1170, 480,320, 480,1220, 480,1170, 480,1170, 530,320, 480,1170, 480,1170, 480,370, 480,1170, 480,370, 480,370, 480,1170, 480,1170, 480,1170, 480,370, 480,1170, 480,370, 480,1170, 480,1220, 430,420, 430,1220, 430,1220, 430,1220, 430,1220, 480,370, 430,1220, 480,1170, 480,370, 480,370, 430,370, 480,370, 480,370, 430,370, 480,370, 480,370, 480,370, 430,370, 480,370, 430,420, 430,420, 430,370, 430,1220, 480,1220, 430,1220, 480,1170, 430};  // Protocol=KASEIKYO Address=0x37B Command=0x0 Extra=0xCB75 Parity fail Raw-Data=0xF00037B5 48 bits LSB first

const uint16_t


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);


void loop() {
    const uint8_t KASEIKYO_KHZ = 38; // 38kHz carrier frequency for the NEC protocol

    Serial.flush();

      
    
    IrSender.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), KASEIKYO_KHZ); // Note the approach used to automatically calculate the size of the array.

    delay(1000); // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
  
}
