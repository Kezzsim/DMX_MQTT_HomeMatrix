#include <Arduino.h>
#include <Preconfig.h>
#include "globals.hpp"
#include "globals.cpp"
#include <SparkFunDMX.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <functionServer.cpp>

SparkFunDMX dmx;

void setup()
{
    Serial.begin(115200);
    Serial.println("Booted (1) ");

    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PW);
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("Connection Failed! Rebooting....");
        delay(5000);
        ESP.restart();
    }
    MDNS.begin("ceiling-matrix");
    startServer();
    Serial.println("Network Online (2) ");
    Serial.println(WiFi.localIP());

    // initialization for complete bus
    dmx.initWrite(TOTAL_CHANNELS);
    Serial.println("DMX Online (3) ");
}

void loop()
{   
    dmx.write(MODE_CHANNEL, GLOBAL_MODE);
    dmx.write(PROGRAM_CHANNEL, GLOBAL_PROGRAM);
    dmx.write(DIMMER_CHANNEL, GLOBAL_DIMMER);
    dmx.write(STROBE_CHANNEL, GLOBAL_STROBE);
    // update the DMX bus with the values that we have written
    dmx.update();
}