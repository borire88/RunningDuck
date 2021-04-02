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
	virtual void setState(bool state) = 0;
	virtual void setPwm(int freq, int duty) = 0;
	virtual ~DigitalOut() {};
};



#endif /* INC_DIGITALOUT_H_ */
