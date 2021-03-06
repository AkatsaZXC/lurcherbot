#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>

int switch_pin = 2; //  Example

//  WiFi and TelegramBot settings
const char* ssid = "SSID";
const char* pass = "PASS";
const char* BotToken[] = "bot_token";

// Initializing TelegramBot
WiFiClientSecure net_ssl;
TelegramBot telegram_bot (BotToken, net_ssl);

void setup(){
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

// Checking WiFi connection
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

Serial.println("WiFi connected!");
Serial.print("ESP8266 IP: ");
Serial.println(WiFi.localIP());

// Starting TelegramBot
telegram_bot.begin();
  
}

void loop(){

  // Checking for new messages
  message m = telegram_bot.getUpdates();

  if(m.text.equals("wifi"))){
    if(WiFi.status() = WL_CONNECTED){
      bot.sendMessage(m.chat_id, "Yes, I am connected to");
      bot.sendMessage(m.chat_id, ssid);
    }else{
      Serial.println("Not connected to WiFi");
    }
  }

  int switch_value = digitalRead(switch_pin);

  if(switch_value == HIGH){
    bot.sendMessage(m.chat_id, "Door opened"); //  0 - closed, 1 - opened
  }
  
  
}
