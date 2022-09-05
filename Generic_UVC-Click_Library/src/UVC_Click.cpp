#include "UVC_Click.h"

UVC_Click::UVC_Click(uint8_t addr) {
	_addr = addr;
}

void UVC_Click::writeByte(byte cmd) {
	_wire->beginTransmission(_addr);
	_wire->write(cmd);
	_wire->endTransmission();
}

void UVC_Click::writeBytes(uint8_t *buffer, size_t size) {
	_wire->beginTransmission(_addr);
	_wire->write(buffer, size);
	_wire->endTransmission();
}

void UVC_Click::readBytes(uint8_t *buffer, size_t size) {
	_wire->requestFrom(_addr, size);
	for (uint16_t i = 0; i < size; i++) {
		buffer[i] = _wire->read();
	}
}

uint16_t UVC_Click::readRawUVCData(){
	uint8_t buffer[2];
	uint16_t rawData;
	readBytes(buffer, 2);
	rawData = buffer[0] << 8 | buffer[1];
	rawData =  rawData & 0x0FFF; // Only 12 lower most bits.
	return rawData;
}

void UVC_Click::begin(TwoWire *wire, uint8_t sda, uint8_t scl, uint32_t freq) {
	_wire = wire;
	_sda  = sda;
	_scl  = scl;
	_freq = freq;
	_wire->begin((int) _sda, (int)_scl, (uint32_t) _freq);
}

float UVC_Click::getVoltage(void){
	uint16_t rawData;
	float voltage;
	rawData = readRawUVCData();
	voltage = ( rawData * 3300 ) / 4096.0f;
	return voltage;
}

float UVC_Click::calculateUVCPower(float voltage ){
	if ( voltage > 0.0f ){
		return voltage / 355.0f;
	}
	return 0.0f;
}

bool UVC_Click::isConnected(){
	int result = 0;
	_wire->beginTransmission(_addr);
    result = Wire.endTransmission();
	// result: 0 = Success.
	return result == 0;
}