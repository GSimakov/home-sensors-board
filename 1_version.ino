#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <map>
#include <string>
#include <any>

struct Config
{
    std::string hardwareID;
    std::string ssid;
    std::string password;
    std::string serverURL;
    unsigned int delay;
};


struct Paths
{
    std::string reg;
    std::string updateDelay;
    std::string updateServerURL;
    std::string updateSSID;
    std::string updatePassword;
    std::string currentMeasurements;
};

// you get the const char* from a std::string by calling c_str().

Config conf;
Paths paths;
HTTPClient http;
WiFiClient client;


void initConfig(){
  conf.hardwareID = "HardwareID1";
  conf.delay = 1000;
  conf.ssid = "gogas";
  conf.password = "12345qwert";
  conf.serverURL = "http://192.168.0.10:8000";

  paths.reg = "/api/v1/reg?hardware_id=" + conf.hardwareID;
  paths.updateConf = "";
  paths.currentMeasurements = "";
}

void connectToWiFi(){
  WiFi.begin(conf.ssid.c_str(), conf.password.c_str());
  Serial.println("Connecting...");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  Serial.println("Connection established");
  }
}


void setup(){
  initConfig();
  Serial.begin(115200);
  connectToWiFi();
}

void loop(){
      Serial.println(paths.reg.c_str());
      delay(conf.delay);
}







void updateDelay(){


}

 
void updateServerURL(){

}

void updateSSID(){

}

void updatePassword(){

}



