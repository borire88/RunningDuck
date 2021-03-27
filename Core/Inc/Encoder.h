/*
 * Encoder.h
 *
 *  Created on: 21 lut 2021
 *      Author: BORONIA
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "DigitalIn.h"

#define NUM_OF_CALLBACKS (2)
typedef void(*encoderCallback)(unsigned int position);

class Encoder {
public:
	Encoder (int pinA, int pinB) : pinA(pinA), pinB(pinB){};
	int getPosition(void);
	unsigned int registerCallback(encoderCallback callback);
private:
	DigitalIn pinA;
	DigitalIn pinB;
	unsigned int position;
	encoderCallback callbacks[NUM_OF_CALLBACKS];
};


#endif /* INC_ENCODER_H_ */
