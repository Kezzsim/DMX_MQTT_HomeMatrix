#include <Arduino.h>
#include "dmxController.h"
#include <SparkFunDMX.h>

SparkFunDMX dmx;

void dmxController::init(){
    Serial.println("starting...");
    // initialization for complete bus
    dmx.initWrite(TOTAL_CHANNELS);
    Serial.println("initialized...");
}

void dmxController::setMatrix(uint8_t mode, uint8_t program, uint8_t dimmer, uint8_t strobe) {
    dmx.write(MODE_CHANNEL, mode);
    dmx.write(PROGRAM_CHANNEL, program);
    dmx.write(DIMMER_CHANNEL, dimmer);
    dmx.write(STROBE_CHANNEL, strobe);
    // update the DMX bus with the values that we have written
    dmx.update(); 
    Serial.println("Received request to update DMX!");
}