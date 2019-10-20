//Propeller.hpp
#pragma once

#ifndef _PROPELLER_HPP
#define _PROPELLER_HPP

#include <Part/PartInterface.hpp>

#include <string>

using namespace std;

class Propeller : public PartInterface {
private :
	unsigned short propSize;
	float propPitch;
	unsigned short blades;
	
public :
	Propeller();
	
	Propeller(string name, float mass, float cost, unsigned short propSize, float propPitch, unsigned short blades);
	
	void setPropSize(unsigned short size);
	unsigned short getPropSize();
	
	void setPitch(float pitch);
	float getPitch();
	
	void setBlades(unsigned short blades);
	unsigned short getBlades();
	
};

#endif //_PROPELLER_HPP
