#include "DigitalOut.h"

class MockDigitalOut : public DigitalOut {
    public:
    MockDigitalOut(int pin) {

    };
	void setState(bool state) {

    };
	void setPwm(int freq, int duty) {

    };
    ~MockDigitalOut() {

    };
};