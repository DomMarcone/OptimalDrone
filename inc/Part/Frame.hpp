//Frame.hpp
#pragma once

#ifndef _FRAME_HPP
#define _FRAME_HPP

#include "PartInterface.hpp"

class Frame : public PartInterface {
private :
	unsigned short prop_size;
	
public :
	Frame();
	
	Frame(string name, float mass, float cost, unsigned short prop_size);
	
	unsigned short getPropSize();
	void setPropSize(unsigned short size);
	
};

#endif //_FRAME_HPP
