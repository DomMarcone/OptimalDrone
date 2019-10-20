//Kit.hpp
#pragma once

#ifndef _KIT_HPP
#define _KIT_HPP

#include <Part/PartInterface.hpp>
#include <Part/FlightController.hpp>
#include <Part/ElectronicSpeedController.hpp>
#include <Part/Battery.hpp>
#include <Part/Frame.hpp>
#include <Part/Motor.hpp>
#include <Part/PowerDistributionBoard.hpp>
#include <Part/Propeller.hpp>
#include <Part/Kit.hpp>

#include <string>

using namespace std;

class Kit : public PartInterface {
private :
	
	FlightController* fc;
	ElectronicSpeedController* esc;
	Battery* battery;	
	Frame* frame;
	Motor* motor;
	PowerDistributionBoard* pdb;
	Propeller* propeller;
	
public :
	
	Kit();
	
	Kit(string name, float mass, float cost);
	
	Kit(FlightController*);
	Kit(ElectronicSpeedController*);
	Kit(Battery*);
	Kit(Frame*);
	Kit(Motor*);
	Kit(PowerDistributionBoard*);
	Kit(Propeller*);
	
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
	
};

#endif //_KIT_HPP
