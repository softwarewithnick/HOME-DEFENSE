# Materials Used

[ARDUINO IDE](https://www.arduino.cc/en/software/)

[ESP32](https://www.amazon.com/Teyleten-Robot-ESP-WROOM-32-Development-Microcontroller/dp/B08246MCL5/ref=sr_1_5?crid=OXDHG4SXBWKD&dib=eyJ2IjoiMSJ9.kzd_BN2te2KAhw5tyJI73nH6ViLFcG8dMAjf7gq3PNvCEPdczvZv3fVNvj1KjPv4xAGfYuMKxOiOZaLIo9mWk-3fqpIa_uXIFRyEJYn0KSCxLZJDBgYhq1RxtzUkW-Mh8yNXgWYZxwatITWA7NGDpbIU8H-TUnpue6N9uYdf0ZhjO7FLFMMlJHpo4aCZyJuKDT5EtjEf-68uLscVrU1YYv7ewQGbpWdBAQEeWf72dIE.ClL5e6mtAE0dNPZCPR7s_RWqLa5TapXIePml0frs1nU&dib_tag=se&keywords=esp32&qid=1756324334&sprefix=esp32%2Caps%2C131&sr=8-5&th=1)

[ULTRASONIC SENSOR](https://www.amazon.com/MTDELE-HC-SR04-Ultrasonic-Arduino-Mounting/dp/B0D6WBK52V/ref=sr_1_2_sspa?crid=1INGN2ETL2P84&dib=eyJ2IjoiMSJ9.dhfoArBcovFZKEbtem8Ow2ycOAbvJFJ7A2ehizrZrECqvTAER2zhPjZdzS47tEIpbUnFG0v4J60F9yybTSQojxao1hB0JgKCGE46aBYd4BHp1aM05Y0ioX7v5nKniVib7OAZG0gXq0lfvwLj8c6Y1t7kgvTq5ntnGPpaE2yLM0BJaz9nN6kBelmcP1pZ6IBkbRNBOG2SXQpNOF4uQPMsLFiY2VwlELgV7dX_EthoMFk.W-k6bReU1juj05LJ9bpmEafSgwTtd_4d9nXQ2RCuaq8&dib_tag=se&keywords=ultrasonic+sensor&qid=1756324459&sprefix=ultrasonic+senso%2Caps%2C118&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

# ESP32 PINOUT
![esp32pinout](https://github.com/user-attachments/assets/ce3a1018-c249-447b-bd6d-f3624d04b465)

# Wiring
### Day 1
- The ESP32 is being powered via micro-usb.
- The 3.3V and GND pin are connected to the Vcc and Gnd pins on the ultrasonic sensor.
- Connect pin 18 (D18) and pin 19 (D19) on the ESP32 to the Trig and Echo pin respectively
<p align="center">
  <img src="https://github.com/user-attachments/assets/00ff161b-a228-4f60-8c7a-19f5cce8c779" width="400" />
  <img src="https://github.com/user-attachments/assets/dea32d06-7f4b-450e-8e9e-b98c1dc7e4ec" width="400" />
</p>
- Upload the arduino script from this repo to your ESP32. You can find many guides on this process on YouTube or elsewhere. Getting your first script up and running on your ESP32 can be a little tricky, but once you do it once it's extremely easy.
- If your script is running correctly and you open your serial monitor in Arduino IDE, you'll see the distances being printed!
