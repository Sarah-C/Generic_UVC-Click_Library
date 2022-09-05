
#include <Arduino.h>
#include <UVC_Click.h>

UVC_Click sensor;

void setup() {
	Serial.begin(112500);
	sensor.begin(&Wire, 25, 21); // SDA, SCL
	delay(2000);
	Serial.println("Reading UVC levels...");
}

void loop() {
	char info[40];
	uint16_t raw_data;
	float voltage;
	float power;

  if(sensor.isConnected()){
    Serial.println("The sensor is connected!");
  }else{
    Serial.println("The sensor is NOT connected!");
  }
  
	raw_data = sensor.readRawUVCData();
	sprintf(info, "Raw data: %d\r\n", raw_data);
	Serial.print(info);

	voltage = sensor.getVoltage();
	sprintf(info, "Voltage: %.4f mV\r\n", voltage);
	Serial.print(info);

	power = sensor.calculateUVCPower(voltage);
	sprintf(info, "Power: %.4f mW/cm2\r\n", power);
	Serial.print(info);

	Serial.println("");
	delay(500);
}
