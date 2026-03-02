#include <esp_now.h>
#include <WiFi.h>
#include <AccelStepper.h>

#define IN1 23
#define IN2 22
#define IN3 21
#define IN4 19

#define STEPS_PER_REV 4096
#define STEPS_90 (STEPS_PER_REV / 4)

#define LED_BUILTIN 2

AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

typedef struct struct_message {
  bool light_on;
} struct_message;

struct_message incomingData;

bool shouldMove = false;
bool motorAt90 = false;

void onReceive(const uint8_t * mac, const uint8_t *incomingDataRaw, int len) {
  memcpy(&incomingData, incomingDataRaw, sizeof(incomingData));

  if (incomingData.light_on) {
    digitalWrite(LED_BUILTIN, HIGH);
    shouldMove = true;  // Just set flag
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  stepper.setMaxSpeed(800);
  stepper.setAcceleration(400);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(onReceive);
}

void loop() {
  // If message received and motor not already moved
  if (shouldMove && !motorAt90) {
    stepper.moveTo(STEPS_90);
    motorAt90 = true;
  }

  // Run motor smoothly
  stepper.run();
}