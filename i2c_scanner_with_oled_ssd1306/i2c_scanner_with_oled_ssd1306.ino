#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Ancho de la pantalla en píxeles
#define SCREEN_HEIGHT 64 // Alto de la pantalla en píxeles
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  byte devices[128];
  byte count = 0;
  for (byte i = 1; i < 127; i++) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      devices[count] = i;
      count++;
    }
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Dispositivos I2C:");
  display.println("");
  for (byte i = 0; i < count; i++) {
    display.print("0x");
    display.print(devices[i], HEX);
    display.println("");
  }
  display.display();
  delay(5000);
}
