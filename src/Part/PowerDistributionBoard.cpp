//PowerDistributionBoard.cpp

#include <Part/PartInterface.hpp>
#include <Part/PowerDistributionBoard.hpp>
#include <Part/PartTypes.h>
#include <string>

using namespace std;

PowerDistributionBoard::PowerDistributionBoard(){
	setType(PDB_FLAG);
}

PowerDistributionBoard::PowerDistributionBoard(string name, float mass, float cost, float maxAmps){
	this->maxAmps = maxAmps;
	
	setName(name);
	setMass(mass);
	setCost(cost);
	setType(PDB_FLAG);
}

void PowerDistributionBoard::setMaxAmps(float maxAmps){	this->maxAmps = maxAmps;	}
float PowerDistributionBoard::getMaxAmps(){	return this->maxAmps;	}

