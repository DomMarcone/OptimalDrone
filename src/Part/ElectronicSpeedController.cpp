//ElectronicSpeedController.cpp

#include <Part/PartInterface.hpp>
#include <Part/ElectronicSpeedController.hpp>
#include <Part/PartTypes.h>
#include <string>

using namespace std;
	
ElectronicSpeedController::ElectronicSpeedController(){
	setType(ESC_FLAG);
}

ElectronicSpeedController::ElectronicSpeedController(
	string name, float mass, float cost, float amps, string firmware, string protocol){
	
	this->amps = amps;
	this->firmware = firmware;
	this->protocol = protocol;
	
	setName(name);
	setMass(mass);
	setCost(cost);
	setType(ESC_FLAG);
}

void ElectronicSpeedController::setAmps(float amps){	this->amps = amps;}
float ElectronicSpeedController::getAmps(){	return this->amps;	}

void ElectronicSpeedController::setFirmware(string firmware){	this->firmware = firmware;	}
string ElectronicSpeedController::getFirmware(){	return this->firmware;	}

void ElectronicSpeedController::setProtocol(string protocol){	this->protocol = protocol;	}
string ElectronicSpeedController::getProtocol(){	return this->protocol;	}
