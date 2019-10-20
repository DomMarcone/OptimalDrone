//PartInterface.hpp
#pragma once

#ifndef _PART_INTERFACE_HPP
#define _PART_INTERFACE_HPP

#include <string>
#include <Part/PartTypes.h>

using namespace std;

class PartInterface{
private :
	string name;
	float cost;
	float mass;
	
	part_t type;
public :
	
	void setName(string name);
	string getName();
	
	void setCost(float cost);
	float getCost();
	
	void setMass(float mass);
	float getMass();
	
	void setType(part_t type);
	part_t getType();
};

#endif //_PART_INTERFACE_HPP

