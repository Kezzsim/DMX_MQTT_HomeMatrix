#include <Arduino.h>
#include "functionServer.hpp"
#include <ESPAsyncWebServer.h>
#include "ArduinoJson.h"
#include <AsyncJson.h>

int ledPin = 13;
AsyncWebServer server(80);

void startServer()
{

    pinMode(ledPin, OUTPUT);

    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, PUT");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "*");

    server.addHandler(new AsyncCallbackJsonWebHandler("/led", [](AsyncWebServerRequest *request, JsonVariant &json) {
    const JsonObject &jsonObj = json.as<JsonObject>();
    if (jsonObj["on"])
    {
      Serial.println("Turn on LED");
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      Serial.println("Turn off LED");
      digitalWrite(ledPin, LOW);
    }
    request->send(200, "OK");
  }));

    server.onNotFound([](AsyncWebServerRequest *request) {
    if (request->method() == HTTP_OPTIONS)
    {
      request->send(200);
    }
    else
    {
      Serial.println("Not found");
      request->send(404, "Not found");
    }
  });

  server.begin();

}