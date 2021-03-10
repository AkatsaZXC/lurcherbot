#include <Arduino.h>
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <ESP_Mail_Client.h>

#define WIFI_SSID "SSID"
#define WIFI_PASS "PASS"

#define SMTP_SERVER "smtp.gmail.com"
#define SMTP_PORT   465

#define AUTHOR_EMAIL "EMAIL"
#define AUTHOR_PASS  "PASS"

SMTPSeddion smtp;


void setup(){
  Serial.begin(115200);
  Serial.println();

  Serial.printt("Connecting to WiFi");

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
  Serial.println();

  smtp.debug(1); // 1- basic debug, 0 - no debug
  //  smtpcallback

  //  Enable SMTP session
  ESP_Mail_Session session;

  //  Session config
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.login.user_domain = "mydomain.net";

  //  Declare message class
  SMTP_Message message;

  //  Set the message headers
  message.sender.name = "ESP MailTest";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = "Test";
  message.addRecipient("Test", "someone_email");

  message.text.content = "Privet";
  
  message.text.charSet = "us-ascii";
  
}
