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
	Encoder(unsigned int nPositions, bool saturation, bool channelA, bool channelB) : numOfPositions(nPositions), saturate(saturation), channelA(channelA), channelB(channelB){
		position = 0;
	};
	void risingEdgeA(void);
	void fallingEdgeA(void);
	void risingEdgeB(void);
	void fallingEdgeB(void);
	int getPosition(void);
	unsigned int registerCallback(encoderCallback callback);
private:
	unsigned int numOfPositions;
	unsigned int position;
	bool saturate;
	bool channelA;
	bool channelB;
	encoderCallback callbacks[NUM_OF_CALLBACKS];
};


#endif /* INC_ENCODER_H_ */
