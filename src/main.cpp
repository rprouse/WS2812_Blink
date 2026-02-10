#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 48

#define BOOTLOG(...)             \
  {                              \
    char buf[120];               \
    sprintf(buf, __VA_ARGS__);   \
    Serial.print("##[BOOT]#\t"); \
    Serial.println(buf);         \
  }

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<SK6812, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(115200);
}

void loop() {
  leds[0] = CRGB::Red;
  FastLED.show();
  Serial.println("RED LED is ON");
  delay(500);
  leds[0] = CRGB::Yellow;
  FastLED.show();
  Serial.println("GREEN LED is ON");
  delay(500);
  leds[0] = CRGB::Blue;
  FastLED.show();
  Serial.println("BLUE LED is ON");
  delay(500);
  leds[0] = CRGB::Black;
  FastLED.show();
  Serial.println("LED's are OFF");

  BOOTLOG("Total heap: %d", ESP.getHeapSize());
  BOOTLOG("Free heap: %d", ESP.getFreeHeap());
  BOOTLOG("Total PSRAM: %d", ESP.getPsramSize());
  BOOTLOG("Free PSRAM: %d", ESP.getFreePsram());

  delay(1500);
}
