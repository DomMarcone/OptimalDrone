//Battery.hpp
#pragma once

#ifndef _BATTERY_HPP
#define _BATTERY_HPP

#include <Part/PartInterface.hpp>
#include <string>

using namespace std;

class Battery : public PartInterface {
private :
	float mWattHours;
	float voltage;
	float cRating;
	
public :
	
	Battery();
	
	Battery(string name, float mass, float cost, float mWattHours, float voltage, float cRating);
	
	void setMWattHours(float mWattHours);
	float getMWattHours();
	
	void setVoltage(float voltage);
	float getVoltage();

	void setCRating(float cRating);
	float getCRating();
	
};

#endif //_BATTERY_HPP
