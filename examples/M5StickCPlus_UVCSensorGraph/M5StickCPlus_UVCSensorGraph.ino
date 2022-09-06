/*
 * 
 * M5StickC Plus sketch for Arduino that uses the GUVC-T21GH sensor
 * to produce an average of UVC light, and a small sample waveform over a few milliseconds.
 * Ideal for checking on oscillating UVC sources.
 * 
 * http://www.geni-uv.com/download/products/GUVC-T21GH.pdf
 * 
*/

#include <M5StickCPlus.h>
#include "UVC_Click.h"

UVC_Click sensor;
TFT_eSprite disbuff = TFT_eSprite(&M5.Lcd);

int graphColor = 0;
int textColor = TFT_GREEN;
int updateSpeed = 250; // millisecond delay

void setup() {
  M5.begin();
  Serial.begin(115200);
	pinMode(25, INPUT);
	pinMode(26, INPUT);
	gpio_pulldown_dis(GPIO_NUM_36);
	gpio_pullup_dis(GPIO_NUM_36);  
  sensor.begin(&Wire, 25, 26); // 25 = SDA, 26 = SCL
  
  M5.Lcd.setRotation(1);
  disbuff.setTextColor(textColor);
  disbuff.setTextDatum(ML_DATUM);
  disbuff.setTextSize(2);
  disbuff.createSprite(240, 135);
  graphColor = disbuff.color565(100, 50, 50);
  disbuff.fillRect(0, 0, 240, 135, disbuff.color565(255, 0, 255));
  disbuff.pushSprite(0, 0);
}

int getSampleAverage(int reads, int wait) {
  long total = 0;
  for (int i = 0; i < 100; i++) {
    total += sensor.readRawUVCData(); //adc1_get_raw(ADC1_CHANNEL_0);
    delay(wait);
  }
  return total / reads;
}

void loop() {
  disbuff.fillSprite(TFT_BLACK);
  getAndDrawWaveform();
  getAndDrawTextValues();
  disbuff.pushSprite(0, 0);
  delay(updateSpeed);
}

void getAndDrawWaveform() {
  double sample = 0;
  int y = 0;
  int oldy = 0;
  uint16_t samples[240];
  for (uint8_t x = 0; x < 240; x++) {
    samples[x] = sensor.readRawUVCData();
    // delayMicroseconds(1);
  }
  sample = (double) samples[0];
  oldy = (int)((sample * 134.0f) / 4095.0f);
  for (uint8_t x = 1; x < 240; x++) {
    sample = (double) samples[x];
    y = (int)((sample * 134.0) / 4095.0);
    disbuff.drawLine(x - 1, 134 - oldy, x, 134 - y, graphColor);
    oldy = y;
  }
}

void getAndDrawTextValues() {
  int stepY = 30; // The the text seperation
  int startY = 12;

  int rawAnalog = 0;
  float voltage = 0;
  float mwcm = 0;

  char info[40]; // Place for sprintf

  rawAnalog = getSampleAverage(100, 1);// Reads to average over, wait between them.
  voltage = (rawAnalog * 3.3f ) / (4095.0f); // (raw / 4095) = 0..1,  3.3 * 0..1 = volts
  mwcm = voltage * 0.355f;

  sprintf(info, "Raw: %d", rawAnalog);
  disbuff.drawString(info, 10, startY);

  sprintf(info, "Volts: %.2f", voltage);
  disbuff.drawString(info, 10, startY + stepY);

  sprintf(info, "mW/cm^2: %.2f", mwcm);
  disbuff.drawString(info, 10, startY + (stepY * 2));
}
