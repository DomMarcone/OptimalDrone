//Propeller.cpp

#include <Part/PartInterface.hpp>
#include <Part/Propeller.hpp>
#include <Part/PartTypes.h>

#include <string>

using namespace std;

Propeller::Propeller(){
	setType(PROPELLER_FLAG);
}

Propeller::Propeller(string name, float mass, float cost, unsigned short propSize, float propPitch, unsigned short blades){
	this->propSize = propSize;
	this->propPitch = propPitch;
	this->blades = blades;
	
	setName(name);
	setMass(mass);
	setCost(cost);
	setType(PROPELLER_FLAG);
}

void Propeller::setPropSize(unsigned short size){	this->propSize = size;	}
unsigned short Propeller::getPropSize(){	return this->propSize;	}

void Propeller::setPitch(float pitch){	this->propPitch = pitch;	}
float Propeller::getPitch(){	return this->propPitch;	}

void Propeller::setBlades(unsigned short blades){	this->blades = blades;	}
unsigned short Propeller::getBlades(){	return this->blades;	}

