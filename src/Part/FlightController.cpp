//FlightController.cpp

#include <Part/PartInterface.hpp>
#include <Part/FlightController.hpp>
#include <Part/PartTypes.h>
#include <string>

using namespace std;

FlightController::FlightController(){
	setType(FLIGHTCONTROLLER_FLAG);
}

FlightController::FlightController(string name, float mass, float cost, string firmware, string processor){
	this->firmware = firmware;
	this->processor = processor;
	
	setName(name);
	setMass(mass);
	setCost(cost);
	setType(FLIGHTCONTROLLER_FLAG);
}

void FlightController::setFirmware(string firmware){	this->firmware = firmware;	}
string FlightController::getFirmware(){	return this->firmware;	}

void FlightController::setProcessor(string processor){	this->processor = processor;	}
string FlightController::getProcessor(){	return this->processor;	}

