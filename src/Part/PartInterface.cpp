//PartInterface.cpp

#include <string>
#include <Part/PartInterface.hpp>
#include <Part/PartTypes.h>

using namespace std;
	
void PartInterface::setName(string name){	this->name = name;	}
string PartInterface::getName(){	return this->name;	}

void PartInterface::setCost(float cost){	this->cost = cost;	}
float PartInterface::getCost(){	return this->cost;	}

void PartInterface::setMass(float mass){	this->mass = mass;	}
float PartInterface::getMass(){	return this->mass;	}

void PartInterface::setType(part_t type){	this->type = type;	}
part_t PartInterface::getType(){	return this->type;	}
