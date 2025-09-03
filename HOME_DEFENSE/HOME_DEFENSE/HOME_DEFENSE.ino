#include <esp_now.h>
#include <WiFi.h>

// MAC address of the receiver ESP32 (update with your receiver’s MAC)
uint8_t receiverAddress[] = {0x6C, 0xC8, 0x40, 0x4E, 0xF2, 0xE0};

// Data structure to send
typedef struct struct_message {
  bool light_on;
} struct_message;

struct_message dataToSend;


const int trigPin = 18;
const int echoPin = 19;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Init WiFi in STA mode
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register send callback
  // esp_now_register_send_cb(onSent);

  // Add receiver as peer
  esp_now_peer_info_t peerInfo;
  memset(&peerInfo, 0, sizeof(peerInfo));          // CLEAR THE STRUCT
  memcpy(peerInfo.peer_addr, receiverAddress, 6);  // MAC address
  peerInfo.channel = 0;                            // use same Wi-Fi channel
  peerInfo.encrypt = false;                        // no encryption
  peerInfo.ifidx = WIFI_IF_STA;                    // <--- explicitly set the interface


  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  } else {
    Serial.println("Peer added OK");
  }
}

void loop() {
  long duration;
  float distance;

  // Send a 10 microsecond pulse to trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin and calculate the distance
  duration = pulseIn(echoPin, HIGH);

  // The ultra-sonic sensor measures time in microseconds.
  // We want the distance measurement in cm.
  // We need to conver the speed of sound to cm/microsecond.

  // Speed of sound is 343 m/s -> 34,300 cm/s
  // There are 1,000,000 microseconds in 1 second
  // 34,300cm/s / 1,000,000 microseconds/s = 0.0343 cm/microsecond

  // Divide final answer by 2 since the time measured is the time it takes
  // for the sound to hit the object and bounce back. We just want the
  // distance to the object, not the distance to the object and back.
  distance = (duration * 0.0343) / 2; 

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 30){
    Serial.println("TURN LIGHT ON");

    dataToSend.light_on = true;

    esp_err_t result = esp_now_send(receiverAddress, (uint8_t *) &dataToSend, sizeof(dataToSend));

    // if (result == ESP_OK) {
    //   Serial.println("Sent successfully");
    // } else {
    //   Serial.println("Error sending data");
    // }    
  }else{
    dataToSend.light_on = false;
      Serial.println("TURN LIGHT OFF");

      esp_err_t result = esp_now_send(receiverAddress, (uint8_t *) &dataToSend, sizeof(dataToSend));

      // if (result == ESP_OK) {
      //   Serial.println("Sent successfully");
      // } else {
      //   Serial.println("Error sending data");
      // }  
  }

  delay(500); // Wait half a second before next reading

  

}
