
#ifndef _UVC_Click_H_
#define _UVC_Click_H_

#include "Arduino.h"
#include "Wire.h"
#include "pins_arduino.h"

// Address: 77
#define DEVICE_I2C_ADDR 0x4D

class UVC_Click {
private:
	TwoWire *_wire;
	uint8_t _sda;
	uint8_t _scl;
	uint32_t _freq;
	uint8_t _addr;
	void writeByte(byte cmd);
	void writeBytes(uint8_t *buffer, size_t size);
	void readBytes(uint8_t *buffer, size_t size);

public:
	UVC_Click(uint8_t addr = DEVICE_I2C_ADDR);
	void begin(TwoWire *wire = &Wire, uint8_t sda = SDA, uint8_t scl = SCL,
				uint32_t freq = 100000UL);

	uint16_t readRawUVCData(); // 12 bits data
	float getVoltage(); 
	float calculateUVCPower(float voltage);
	bool isConnected();
};

#endif