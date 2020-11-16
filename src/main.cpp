#include <Arduino.h>
#include <Preconfig.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <SparkFunDMX.h>
#include <functionServer.cpp>
#include <ESPAsyncWebServer.h>
#include <AsyncJson.h>

void setup()
{
    SparkFunDMX dmx;
    Serial.begin(115200);
    Serial.println("Booted");
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PW);
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("Connection Failed! Rebooting....");
        delay(5000);
        ESP.restart();
    }
    MDNS.begin("ceiling-matrix");
    Serial.println("Network Online : ");
    Serial.println(WiFi.localIP());
    startServer();
}

void loop()
{

}