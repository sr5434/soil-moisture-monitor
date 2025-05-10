#include <LiquidCrystal_I2C.h>


#define SENSOR_INPUT 36
#define LIGHT_PORT 12

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  esp_log_level_set("*", ESP_LOG_VERBOSE);
  pinMode(LIGHT_PORT, OUTPUT);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorOutput = analogRead(SENSOR_INPUT);
  int humidityPercentage = map(sensorOutput, 0, 4095, 100, 0);
  if (humidityPercentage < 30) {
    digitalWrite(LIGHT_PORT, HIGH);
  } else {
    digitalWrite(LIGHT_PORT, LOW);
  }
  lcd.setCursor(1,0);
  lcd.print("Soil Humidity:");
  lcd.setCursor(6,1);
  lcd.print(String(humidityPercentage)+"%");
}
