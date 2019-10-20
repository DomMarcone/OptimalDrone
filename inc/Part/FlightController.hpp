//FlightController.hpp
#pragma once

#ifndef _FLIGHTCONTROLLER_HPP
#define _FLIGHTCONTROLLER_HPP

#include <Part/PartInterface.hpp>
#include <string>

using namespace std;

class FlightController : public PartInterface {
private :
	string firmware;
	string processor;
	
public :
	
	FlightController();
	
	FlightController(string name, float mass, float cost, string firmware, string processor);
	
	void setFirmware(string firmware);
	string getFirmware();
	
	void setProcessor(string processor);
	string getProcessor();
	
};

#endif //_FLIGHTCONTROLLER_HPP
