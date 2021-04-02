/*
 * Motor.h
 *
 *  Created on: Feb 13, 2021
 *      Author: BORONIA
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "DigitalOut.h"

class Motor {
public:
	Motor(DigitalOut* pwmPin, DigitalOut* controlPin1, DigitalOut* controlPin2) : pwmPin(pwmPin), controlPin1(controlPin1), controlPin2(controlPin2){
		speed = 0;
	};
	int getSpeed(void);
	void setSpeed(int speed);
	void stop(void);
private:
	int speed;
	DigitalOut* pwmPin;
	DigitalOut* controlPin1;
	DigitalOut* controlPin2;
};



#endif /* INC_MOTOR_H_ */
