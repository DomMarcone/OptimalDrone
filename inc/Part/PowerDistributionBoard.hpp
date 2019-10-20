//PowerDistributionBoard.hpp
#pragma once

#ifndef _POWERDISTRIBUTIONBOARD_HPP
#define _POWERDISTRIBUTIONBOARD_HPP

#include <Part/PartInterface.hpp>
#include <string>

using namespace std;

class PowerDistributionBoard : public PartInterface {
private :
	float maxAmps;
	
public :
	
	PowerDistributionBoard();
	
	PowerDistributionBoard(string name, float mass, float cost, float maxAmps);
	
	void setMaxAmps(float maxAmps);
	float getMaxAmps();
	
};

#endif //_POWERDISTRIBUTIONBOARD_HPP
