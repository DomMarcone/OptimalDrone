//Drone.hpp
#pragma once

#ifndef _DRONE_HPP
#define _DRONE_HPP

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

#include <vector>

class Drone {
private :
	
	FlightController* fc;
	ElectronicSpeedController* esc;
	Battery* battery;	
	Frame* frame;
	Motor* motor;
	PowerDistributionBoard* pdb;
	Propeller* propeller;
	
	part_t type;
	
	std::vector<Kit *> parts;
	void removeFromVector(Kit *k);
	
	static part_t complete;
	
public :
	
	Drone();
	
	static void setCompleteType(part_t part);
	
	void showParts();
	void showFlags();
	
	void setFlightController(FlightController *fc);
	FlightController* getFlightController();
	
	void setElectronicSpeedController(ElectronicSpeedController *esc);
	ElectronicSpeedController* getElectronicSpeedController();
	
	void setBattery(Battery *battery);
	Battery* getBattery();
	
	void setFrame(Frame *frame);
	Frame* getFrame();
	
	void setMotor(Motor *motor);
	Motor* getMotor();
	
	void setPowerDistributionBoard(PowerDistributionBoard *pdb);
	PowerDistributionBoard* getPowerDistributionBoard();
	
	void setPropeller(Propeller *propeller);
	Propeller* getPropeller();
	
	bool isComplete();
	
	bool isAddable(Kit *p);
	
	void addPart(Kit *p);
	void removePart(Kit *p);
	
};

#endif //_DRONE_HPP
