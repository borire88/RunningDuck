/*
 * Motor.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: BORONIA
 */

#include "Motor.h"
#include "math.h"

int Motor::getSpeed() {
	return this->speed;
}

void Motor::setSpeed(int speed) {
	static const int pwmFreq = 10000;
	//DigitalOut* primaryOutPtr = &(this->controlPin1);
	//DigitalOut* secondaryOutPtr = &(this->controlPin2);

	if(speed < 0){
		//primaryOutPtr = &(this->controlPin1);
		//secondaryOutPtr = &(this->controlPin2);
	}

	speed = std::abs(speed);
	if(speed > 100)
	{
		speed = 100;
	}

	if(speed == 0) {
		//primaryOutPtr->setState(false);
		//secondaryOutPtr->setState(false);
		//pwmPin.setState(true);
	}
	else {
		//primaryOutPtr->setState(true);
		//secondaryOutPtr->setState(false);
		//pwmPin.setPwm(pwmFreq, speed);
	}
	this->speed = speed;
}

void Motor::stop(void) {
	setSpeed(0);
}
