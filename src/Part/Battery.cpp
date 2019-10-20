//Battery.cpp

#include <Part/PartInterface.hpp>
#include <Part/Battery.hpp>
#include <Part/PartTypes.h>

using namespace std;

Battery::Battery(){
	setType(BATTERY_FLAG);
}

Battery::Battery(string name, float mass, float cost, float mWattHours, float voltage, float cRating){
	this->mWattHours = mWattHours;
	this->voltage = voltage;
	this->cRating = cRating;
	
	setName(name);
	setMass(mass);
	setCost(cost);
	setType(BATTERY_FLAG);
}

void Battery::setMWattHours(float mWattHours){	this->mWattHours = mWattHours;	}
float Battery::getMWattHours(){	return this->mWattHours;	}

void Battery::setVoltage(float voltage){	this->voltage = voltage;	}
float Battery::getVoltage(){	return this->voltage;	}

void Battery::setCRating(float cRating){	this->cRating = cRating;	}
float Battery::getCRating(){	return this->cRating;	}
