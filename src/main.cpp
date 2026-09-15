#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <Servo.h>

/* Wifi network station credentials */
#define WIFI_SSID "Ваша назва WiFi"
#define WIFI_PASSWORD "ваш пароль WiFi"

/* Telegram BOT Token (Get from Botfather) */
#define BOT_TOKEN "8741119875:AAE0vo48bCJ5qMLp5mtzmATU2TzBIZ3WBxU"
// Use @myidbot (IDBot) to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
String chat_id = "8741119875";

Servo myservo;

const unsigned long BOT_MTBS = 1000; // mean time between scan messages
unsigned long bot_lasttime;          // last time messages' scan has been done

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void handleNewMessages(int numNewMessages)
{
  Serial.print("handleNewMessages ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++)
  {
    // String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;

    if (text == "/s0")
    {
      myservo.write(0);
      bot.sendMessage(chat_id, "Servo set at 0 degrees", "");
    }

    if (text == "/s45")
    {
      myservo.write(45);
      bot.sendMessage(chat_id, "Servo set at 45 degrees", "");
    }

    if (text == "/s90")
    {
      myservo.write(90);
      bot.sendMessage(chat_id, "Servo set at 90 degrees", "");
    }

    if (text == "/s135")
    {
      myservo.write(135);
      bot.sendMessage(chat_id, "Servo set at 135 degrees", "");
    }

    if (text == "/s180")
    {
      myservo.write(180);
      bot.sendMessage(chat_id, "Servo set at 180 degrees", "");
    }

    if (text == "/help")
    {
      String welcome = "Welcome to ESP8266 WiFi Telegram Test!\n";
      welcome += "/s45 : set Servo to 0 degrees\n";
      welcome += "/s45 : set Servo to 45 degrees\n";
      welcome += "/s90 : set Servo to 90 degrees\n";
      welcome += "/s135 : set Servo to 135 degrees\n";
      welcome += "/s180 : set Servo to 180 degrees\n";
      welcome += "/temp : Get temperature data\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println();

  // attempt to connect to Wifi network:
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(chat_id, "ESP8266 WiFi Telegram Test is Started!", "");

  myservo.attach(0);
}

void loop()
{
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    bot_lasttime = millis();
  }
}
