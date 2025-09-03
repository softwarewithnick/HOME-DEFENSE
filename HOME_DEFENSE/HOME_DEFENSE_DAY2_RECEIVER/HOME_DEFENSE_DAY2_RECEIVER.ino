#include <esp_now.h>
#include <WiFi.h>

#define LED_BUILTIN 2

// Data structure must match the sender
typedef struct struct_message {
  bool light_on;
} struct_message;

struct_message incomingData;

// Callback when data is received
void onReceive(const uint8_t * mac, const uint8_t *incomingDataRaw, int len) {
  memcpy(&incomingData, incomingDataRaw, sizeof(incomingData));

  if(incomingData.light_on == true){
    digitalWrite(LED_BUILTIN, HIGH);
  }else if(incomingData.light_on == false){
    digitalWrite(LED_BUILTIN, LOW);
  }

}

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  // Init WiFi in STA mode
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register receive callback
  esp_now_register_recv_cb(onReceive);
}

void loop() {
  // Nothing needed, data is received in the callback
}
