//ElectronicSpeedController.hpp
#pragma once

#ifndef _ELECTRONICSPEEDCONTROLLER_HPP
#define _ELECTRONICSPEEDCONTROLLER_HPP

#include <Part/PartInterface.hpp>
#include <string>

using namespace std;

class ElectronicSpeedController : public PartInterface {
private :
	float amps;
	string firmware;
	string protocol;
	
public :
	
	ElectronicSpeedController();
	
	ElectronicSpeedController(string name, float mass, float cost, float amps, string firmware, string protocol);
	
	void setAmps(float amps);
	float getAmps();
	
	void setFirmware(string firmware);
	string getFirmware();
	
	void setProtocol(string protocol);
	string getProtocol();
	
};

#endif //_ELECTRONICSPEEDCONTROLLER_HPP
