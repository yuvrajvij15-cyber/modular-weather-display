#include "WeatherLEDs.h"

WeatherLEDs::WeatherLEDs(int l1, int l2 , int l3,int l4, int l5, int l6){
	_l1 = l1; _l2 = l2;
	_l3 = l3; _l4 = l4;
	_l5 = l5; _l6 = l6;
}

void WeatherLEDs::begin(){
	pinMode(_l1, OUTPUT); pinMode(_l2,OUTPUT);
	pinMode(_l3, OUTPUT); pinMode(_l4,OUTPUT);
	pinMode(_l5, OUTPUT); pinMode(_l6,OUTPUT);

}
void WeatherLEDs::allOff(){
	digitalWrite(_l1, LOW); digitalWrite(_l2,LOW);
	digitalWrite(_l3, LOW); digitalWrite(_l4,LOW);
	digitalWrite(_l5, LOW); digitalWrite(_l6,LOW);
}
void WeatherLEDs::allOn(){
	digitalWrite(_l1, HIGH); digitalWrite(_l2,HIGH);
	digitalWrite(_l3, HIGH); digitalWrite(_l4,HIGH);
	digitalWrite(_l5, HIGH); digitalWrite(_l6,HIGH);

}

void WeatherLEDs::display(String description){
	if (description == "scattered clouds"){
	digitalWrite(_l1, LOW); digitalWrite(_l2,LOW);
	digitalWrite(_l3, HIGH); digitalWrite(_l4,HIGH);
	digitalWrite(_l5, LOW); digitalWrite(_l6,LOW);
	}
	else if (description == "clear sky" || description == "few clouds"){
	digitalWrite(_l1, LOW); digitalWrite(_l2,LOW);
	digitalWrite(_l3, HIGH); digitalWrite(_l4,LOW);
	digitalWrite(_l5, LOW); digitalWrite(_l6,LOW);
	}
	else if (description == "snow"){
	digitalWrite(_l1, HIGH); digitalWrite(_l2,LOW);
	digitalWrite(_l3, LOW); digitalWrite(_l4,LOW);
	digitalWrite(_l5, LOW); digitalWrite(_l6,LOW);
	}
	else if (description == "rain"){
	digitalWrite(_l1, LOW); digitalWrite(_l2,LOW);
	digitalWrite(_l3, LOW); digitalWrite(_l4,HIGH);
	digitalWrite(_l5, HIGH); digitalWrite(_l6,LOW);
	}
	else if (description == "thunderstorm"){
	digitalWrite(_l1, LOW); digitalWrite(_l2,LOW);
	digitalWrite(_l3, LOW); digitalWrite(_l4,HIGH);
	digitalWrite(_l5, HIGH); digitalWrite(_l6,HIGH);
	}
	else if (description == "mist"){
	digitalWrite(_l1, LOW); digitalWrite(_l2,HIGH);
	digitalWrite(_l3, LOW); digitalWrite(_l4,LOW);
	digitalWrite(_l5, LOW); digitalWrite(_l6,LOW);
	}
	else{
	allOff();
	}
}
		
		


	
