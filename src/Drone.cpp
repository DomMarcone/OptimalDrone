//Drone.cpp

#include <Part/PartInterface.hpp>
#include <Part/FlightController.hpp>
#include <Part/ElectronicSpeedController.hpp>
#include <Part/Battery.hpp>
#include <Part/Frame.hpp>
#include <Part/Motor.hpp>
#include <Part/PowerDistributionBoard.hpp>
#include <Part/Propeller.hpp>
#include <Part/Kit.hpp>

#include <Part/PartTypes.h>

#include <Drone.hpp>

#include <vector>
#include <iostream>

//Flags that need set on a completed drone.
part_t Drone::complete = FRAME_FLAG | MOTOR_FLAG |
	ESC_FLAG | FLIGHTCONTROLLER_FLAG | PDB_FLAG |
	BATTERY_FLAG | PROPELLER_FLAG;


Drone::Drone(){
	this->fc = 0;
	this->esc = 0;
	this->battery = 0;
	this->frame = 0;
	this->motor = 0;
	this->pdb = 0;
	this->propeller = 0;	
	
	this->type = 0;
}

//Set what a completed drone should like
void Drone::setCompleteType(part_t complete){
	Drone::complete = complete;
}


void Drone::showParts(){
	cout << "Drone parts :" << endl;
	cout << " *FlightController : " << (this->fc ? this->fc->getName() : "none") << endl;
	cout << " *ESC              : " << (this->esc ? this->esc->getName() : "none") << endl;
	cout << " *Battery          : " << (this->battery ? this->battery->getName() : "none") << endl;
	cout << " *Frame            : " << (this->frame ? this->frame->getName() : "none") << endl;
	cout << " *Motor            : " << (this->motor ? this->motor->getName() : "none") << endl;
	cout << " *PDB_FLAG         : " << (this->pdb ? this->pdb->getName() : "none") << endl;
	cout << " *Propeller        : " << (this->propeller ? this->propeller->getName() : "none") << endl;
	cout << "	-raw type : " << this->type << endl << endl;
}

void Drone::showFlags(){
	cout << "Drone flags : ";
	cout << (this->type&PROPELLER_FLAG ? 1 : 0);
	cout << (this->type&PDB_FLAG ? 1 : 0);
	cout << (this->type&MOTOR_FLAG ? 1 : 0);
	cout << (this->type&FRAME_FLAG ? 1 : 0);
	cout << (this->type&BATTERY_FLAG ? 1 : 0);
	cout << (this->type&ESC_FLAG ? 1 : 0);
	cout << (this->type&FLIGHTCONTROLLER_FLAG ? 1 : 0);
	cout << endl;
}

FlightController* Drone::getFlightController(){	return this->fc;	}
void Drone::setFlightController(FlightController *fc){
	this->fc = fc;
	if(fc){
		this->type |= fc->getType();//if we're not setting this to 0
	} else {
		this->type &= ~FLIGHTCONTROLLER_FLAG;//were removing the part...
	}
}


ElectronicSpeedController* Drone::getElectronicSpeedController(){
	return this->esc;
}
void Drone::setElectronicSpeedController(ElectronicSpeedController *esc){
	this->esc = esc;
	if(esc){
		this->type |= esc->getType();
	} else {
		this->type &= ~ESC_FLAG;
	}
}


Battery* Drone::getBattery(){	return this->battery;	}
void Drone::setBattery(Battery *battery){
	this->battery = battery;
	if(battery){
		this->type |= battery->getType();
	} else {
		this->type &= ~BATTERY_FLAG;
	}
}


Frame* Drone::getFrame(){	return this->frame;	}
void Drone::setFrame(Frame *frame){
	this->frame = frame;
	if(frame){
		this->type |= frame->getType();
	} else {
		this->type &= ~FRAME_FLAG;
	}
}

Motor* Drone::getMotor(){	return this->motor;	}
void Drone::setMotor(Motor *motor){
	this->motor = motor;
	if(motor){
		this->type |= motor->getType();
	}else{
		this->type &= ~MOTOR_FLAG;		
	} 
}


PowerDistributionBoard* Drone::getPowerDistributionBoard(){	
	return this->pdb;
}
void Drone::setPowerDistributionBoard(PowerDistributionBoard *pdb){
	this->pdb = pdb;
	if(pdb){
		this->type |= pdb->getType();
	} else {
		this->type &= ~PDB_FLAG;
	}
}


Propeller* Drone::getPropeller(){	return this->propeller;	}
void Drone::setPropeller(Propeller *propeller){
	this->propeller = propeller;	
	if(propeller){
		this->type |= propeller->getType();
	}
	else {
		this->type &= ~PROPELLER_FLAG;
	}
}


bool Drone::isComplete(){
	//Return true, even if it has extra parts.
	if( (this->type & Drone::complete) == Drone::complete )return true;
	return false;
}

bool Drone::isAddable(Kit *p){
	if(!p)return false; //sanity test
	
	/*
	**	Sorry for the bit logic.
	**	
	**	So, if any of the part flags of the current
	**	configuration overlap any in the prospective
	**	part, logically anding them won't equal 0.
	**	
	**	Likewise, if neither have any overlap, they
	**	can be merged.
	*/
	
	if( (this->type & p->getType()) == 0 ) return true;
	
	return false;
} 


void Drone::addPart(Kit *p){
	part_t kitType = p->getType();
	
	if(kitType & FLIGHTCONTROLLER_FLAG){
		this->setFlightController(p->getFlightController());
	}
	
	if(kitType & ESC_FLAG){
		this->setElectronicSpeedController(
			p->getElectronicSpeedController()
		);
	}
	
	if(kitType & BATTERY_FLAG){
		this->setBattery(p->getBattery());
	}
	
	if(kitType & FRAME_FLAG){
		this->setFrame(p->getFrame());
	}
	
	if(kitType & MOTOR_FLAG){
		this->setMotor(p->getMotor());
	}
	
	if(kitType & PDB_FLAG){
		this->setPowerDistributionBoard(
			p->getPowerDistributionBoard()
		);
	}
	
	if(kitType & PROPELLER_FLAG){
		this->setPropeller(p->getPropeller());
	}
	
	this->parts.push_back(p);
}


//****REMOVE PART*****//
void Drone::removeFromVector(Kit *p){
	for(int i=0; i<parts.size(); ++i){
		if(parts[i]==p){
			parts.erase(parts.begin() + i);
			return;
		}
	}
}

void Drone::removePart(Kit *p){
	part_t kitType = p->getType();
	
	if(kitType & FLIGHTCONTROLLER_FLAG){
		this->setFlightController(0);
	}
	
	if(kitType & ESC_FLAG){
		this->setElectronicSpeedController(0);
	}
	
	if(kitType & BATTERY_FLAG){
		this->setBattery(0);
	}
	
	if(kitType & FRAME_FLAG){
		this->setFrame(0);
	}
	
	if(kitType & MOTOR_FLAG){
		this->setMotor(0);
	}
	
	if(kitType & PDB_FLAG){
		this->setPowerDistributionBoard(0);
	}
	
	if(kitType & PROPELLER_FLAG){
		this->setPropeller(0);
	}
	
	this->removeFromVector(p);
}

