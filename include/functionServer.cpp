#include <Arduino.h>
#include "functionServer.hpp"
#include "globals.hpp"
#include <ESPAsyncWebServer.h>
#include <AsyncJson.h>


AsyncWebServer server(80);

void startServer()
{

    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, PUT");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "*");

    server.addHandler(new AsyncCallbackJsonWebHandler("/matrix", [](AsyncWebServerRequest *request, JsonVariant &json) {
    const JsonObject &jsonObj = json.as<JsonObject>();
    
    if (jsonObj["mode"])
    {
        GLOBAL_MODE = jsonObj["mode"];
    }
    if (jsonObj["program"])
    {
        GLOBAL_PROGRAM = jsonObj["program"];
    }
    if (jsonObj["dimmer"])
    {
        GLOBAL_DIMMER = jsonObj["dimmer"];
    }
    if (jsonObj["strobe"])
    {
        GLOBAL_STROBE = jsonObj["strobe"];
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