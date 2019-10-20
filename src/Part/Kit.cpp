//Kit.cpp

#include <Part/PartInterface.hpp>
#include <Part/Kit.hpp>
#include <Part/PartTypes.h>

#include <Part/FlightController.hpp>
#include <Part/ElectronicSpeedController.hpp>
#include <Part/Battery.hpp>
#include <Part/Frame.hpp>
#include <Part/Motor.hpp>
#include <Part/PowerDistributionBoard.hpp>
#include <Part/Propeller.hpp>

#include <string>

using namespace std;

Kit::Kit(){
	setType(0);
}

Kit::Kit(string name, float mass, float cost){
	setName(name);
	setMass(mass);
	setCost(cost);
	setType(0);
}

Kit::Kit(FlightController* fc){	
	setType(0);
	setFlightController(fc); 
}

Kit::Kit(ElectronicSpeedController* esc){
	setType(0);
	setElectronicSpeedController(esc);
}

Kit::Kit(Battery* b){
	setType(0);
	setBattery(b); 
}

Kit::Kit(Frame* f){
	setType(0);
	setFrame(f); 
}

Kit::Kit(Motor* m){
	setType(0);
	setMotor(m);
}


Kit::Kit(PowerDistributionBoard* pdb){
	setType(0);
	setPowerDistributionBoard(pdb); 
}

Kit::Kit(Propeller* p){
	setType(0);
	setPropeller(p); 
}

FlightController* Kit::getFlightController(){	return this->fc;	}
void Kit::setFlightController(FlightController *fc){
	if(!fc)return;	//sanity check
	this->fc = fc;
	
	setType( getType() | fc->getType());
}


ElectronicSpeedController* Kit::getElectronicSpeedController(){	return this->esc;	}
void Kit::setElectronicSpeedController(ElectronicSpeedController *esc){
	if(!esc)return;
	this->esc = esc;
	
	setType( getType() | esc->getType());
}


Battery* Kit::getBattery(){	return this->battery;	}
void Kit::setBattery(Battery *battery){
	if(!battery)return;
	this->battery = battery;
	
	setType( getType() | battery->getType());
}


Frame* Kit::getFrame(){	return this->frame;	}
void Kit::setFrame(Frame *frame){
	if(!frame)return;
	this->frame = frame;
	
	setType( getType() | frame->getType());
}

Motor* Kit::getMotor(){	return this->motor;	}
void Kit::setMotor(Motor *motor){
	if(!motor)return;
	this->motor = motor;
	
	setType( getType() | motor->getType());
}


PowerDistributionBoard* Kit::getPowerDistributionBoard(){	return this->pdb;	}
void Kit::setPowerDistributionBoard(PowerDistributionBoard *pdb){
	if(!pdb)return;
	this->pdb = pdb;
	
	setType( getType() | pdb->getType());
}


Propeller* Kit::getPropeller(){	return this->propeller;	}
void Kit::setPropeller(Propeller *propeller){
	if(!propeller)return;
	this->propeller = propeller;
	
	setType( getType() | propeller->getType());
}
	
