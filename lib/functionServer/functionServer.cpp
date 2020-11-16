#include <Arduino.h>
#include "functionServer.hpp"
#include <ESPAsyncWebServer.h>
#include <AsyncJson.h>
#include "dmxController.cpp"

dmxController xxx;

AsyncWebServer server(80);

void startServer()
{
    xxx.init();

    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, PUT");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "*");

    server.addHandler(new AsyncCallbackJsonWebHandler("/matrix", [](AsyncWebServerRequest *request, JsonVariant &json) {
    const JsonObject &jsonObj = json.as<JsonObject>();
    // Set default values for the Matrix Macros
    uint8_t mode = 0 ;
    uint8_t program = 0;
    uint8_t dimmer = 0;
    uint8_t strobe = 0;

    if (jsonObj["mode"])
    {
        mode = jsonObj["mode"];
    }
    if (jsonObj["program"])
    {
        program = jsonObj["program"];
    }
    if (jsonObj["dimmer"])
    {
        dimmer = jsonObj["dimmer"];
    }
    if (jsonObj["strobe"])
    {
        strobe = jsonObj["strobe"];
    }

    // Send the values set to the DMX Matrix
    xxx.setMatrix(mode, program, dimmer, strobe);

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