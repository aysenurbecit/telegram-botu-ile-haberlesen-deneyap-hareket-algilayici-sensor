#include <deneyap.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <Deneyap_HareketAlgilama.h>  

// Bağlanılacak WiFi bilgileri
const char* ssid = "XXXXXXXXXXXXX";
const char* password = "XXXXXXXX";

unsigned char Hareket; 
int hareket;

// Telegramdan oluşturulan BOT bilgileri 
#define BOTtoken "000000000000000000000000000000000000000" // Telegram uygulaması üzerinden Botfather ile öğrendiğiniz botID yi buraya yapıştırın.
#define CHAT_ID "0000000000" // botID ile chatID'sini öğrenip buraya yapıştırın.

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setup() {
Serial.begin(115200);                               // Seri monitör başlatılması
    if (!Hareket.begin(0x32)) {                         // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri monitore yazdırılması
        while (1);
    }
 pinMode(Hareket, INPUT);

  Serial.begin(115200);
  
  client.setInsecure();
  Serial.print("İnternete bağlanıyor: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi bağlandı");
  Serial.print("IP adresi: ");
  Serial.println(WiFi.localIP());
  bot.sendMessage(CHAT_ID, "Cihaz aktif.");
}
void loop() {
hareket = digitalRead(pir);
  if(hareket == HIGH){
    digitalWrite(led, HIGH);
    Serial.print("1");
    bot.sendMessage(CHAT_ID, "HAREKET ALGILANDI");
  }
  else{
    digitalWrite(led, LOW);
    Serial.print("0");
}
Serial.println("G");

}
