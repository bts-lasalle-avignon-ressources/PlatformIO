#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>

// Configuration du WiFi avec WiFiManager
WiFiManager wm;
WiFiClient  espClient;

uint8_t esp32Led = 1; // LED_BUILTIN

void setup()
{
    Serial.begin(115200);

    // Configuration du WiFi avec WiFiManager
    WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
    // reset settings - wipe credentials for testing
    // wm.resetSettings();
    wm.setTitle("Station de notifications lumineuses");
    // wm.setDarkMode(true);
    bool resultat = false;
    resultat      = wm.autoConnect(); // auto generated AP name from chipid
    if(!resultat)
    {
        Serial.println(F("Erreur de connexion !"));
        // ESP.restart();
    }
    // fin de la configuration du WiFi avec WiFiManager

    // Port par défaut : 3232
    // ArduinoOTA.setPort(3232);

    // Hostname par défaut : esp3232-[MAC]
    // ArduinoOTA.setHostname("ESP32_F3AB6224");

    // OTA
    /*
    ArduinoOTA
      .onStart(
        []()
        {
            // cf. ArduinoOTA.getCommand()
            Serial.println("Start OTA updating");
        })
      .onEnd(
        []()
        {
            Serial.println("End OTA updating");
        })
      .onProgress(
        [](unsigned int progress, unsigned int total)
        {
            Serial.printf("Progress OTA updating: %u%%\r",
                          (progress / (total / 100)));
        })
      .onError(
        [](ota_error_t error)
        {
            Serial.printf("Error OTA updating [%u]: ", error);
            if(error == OTA_AUTH_ERROR)
            {
                Serial.println("Auth Failed");
            }
            else if(error == OTA_BEGIN_ERROR)
            {
                Serial.println("Begin Failed");
            }
            else if(error == OTA_CONNECT_ERROR)
            {
                Serial.println("Connect Failed");
            }
            else if(error == OTA_RECEIVE_ERROR)
            {
                Serial.println("Receive Failed");
            }
            else if(error == OTA_END_ERROR)
            {
                Serial.println("End Failed");
            }
        });
    */
    ArduinoOTA.begin();

    pinMode(esp32Led, OUTPUT);
#ifdef DEBUG
    Serial.println("Setup done");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
#endif
}

void loop()
{
    ArduinoOTA.handle();
#ifdef DEBUG
    Serial.println("Start blink");
#endif
    // Hello world!, non blink!
    digitalWrite(esp32Led, HIGH);
    delay(1000);
    digitalWrite(esp32Led, LOW);
    delay(5000);
}
