/*
 * Encoder.cpp
 *
 *  Created on: 21 lut 2021
 *      Author: BORONIA
 */

#include "Encoder.h"

void Encoder::risingEdgeA(void) {
	channelA = true;
}

void Encoder::fallingEdgeA(void) {
	channelA = false;
}

void Encoder::risingEdgeB(void) {
	channelB = true;
	if(channelA == false) {
		position++;
		if(position >= numOfPositions) {
			if(saturate == true) {
				position = numOfPositions - 1;
			}
			else {
				position = 0;
			}
		}
	}
	else {
		if(position == 0) {
			if(saturate == false) {
				position = numOfPositions - 1;
			}
		}
		else {
			position--;
		}
	}
}

void Encoder::fallingEdgeB(void) {
	channelB = false;
}

int Encoder::getPosition(void) {
	return position;
}

