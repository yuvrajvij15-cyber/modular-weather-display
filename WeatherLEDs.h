#ifndef WeatherLEDs_h
#define WeatherLEDs_h

#include <Arduino.h>

class WeatherLEDs {
	private:
	   int _l1 , _l2 ,_l3, _l4, _l5, _l6;
	public:
	WeatherLEDs(int l1, int l2, int l3, int l4, int l5, int l6);
	void begin();
	void display(String description);
	void allOff();
	void allOn();

};

#endif