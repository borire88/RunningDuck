/*
 * DigitalOut.h
 *
 *  Created on: 27 lut 2021
 *      Author: BORONIA
 */

#ifndef INC_DIGITALOUT_H_
#define INC_DIGITALOUT_H_

class DigitalOut {
public:
	DigitalOut(int pin) {

	};
	void setState(bool state);
	void setPwm(int freq, int duty);

};



#endif /* INC_DIGITALOUT_H_ */
