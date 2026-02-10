#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 48

#define LOG(...)                 \
    {                                \
        char buf[120];               \
        sprintf(buf, __VA_ARGS__);   \
        Serial.print("[LOG] "); \
        Serial.println(buf);         \
    }

CRGB leds[NUM_LEDS];

void setup()
{
    FastLED.addLeds<SK6812, DATA_PIN, GRB>(leds, NUM_LEDS);
    Serial.begin(115200);
}

void loop()
{
    LOG("Total heap: %d", ESP.getHeapSize());
    LOG("Free heap: %d", ESP.getFreeHeap());
    LOG("Total PSRAM: %d", ESP.getPsramSize());
    LOG("Free PSRAM: %d", ESP.getFreePsram());

    leds[0] = CRGB::Red;
    FastLED.show();
    LOG("RED LED is ON");
    delay(500);

    leds[0] = CRGB::Blue;
    FastLED.show();
    LOG("BLUE LED is ON");
    delay(500);
}
