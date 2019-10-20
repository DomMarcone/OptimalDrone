//Frame.cpp

#include <Part/PartInterface.hpp>
#include <Part/PartTypes.h>
#include <Part/Frame.hpp>

Frame::Frame(){
	setType(FRAME_FLAG);
}

Frame::Frame(string name, float mass, float cost, unsigned short prop_size){
	this->prop_size = prop_size;
	
	setName(name);
	setMass(mass);
	setCost(cost);
	setType(FRAME_FLAG);
}

unsigned short Frame::getPropSize(){	return this->prop_size;	}
void Frame::setPropSize(unsigned short size){	this->prop_size = size;	}

