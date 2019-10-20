//TotalMass.cpp

#include <Metric/MetricInterface.hpp>
#include <Metric/TotalMass.hpp>

#include <Part/PartInterface.hpp>
#include <Part/FlightController.hpp>
#include <Part/ElectronicSpeedController.hpp>
#include <Part/Battery.hpp>
#include <Part/Frame.hpp>
#include <Part/Motor.hpp>
#include <Part/PowerDistributionBoard.hpp>
#include <Part/Propeller.hpp>
#include <Part/Kit.hpp>

#include <Drone.hpp>

TotalMass::TotalMass(){
	setName("mass");
}

float TotalMass::calculate(Drone &d){
	float result = 0.f;
	
	result += d.getFlightController()->getMass();
	result += d.getElectronicSpeedController()->getMass();
	result += d.getBattery()->getMass();
	result += d.getFrame()->getMass();
	result += d.getMotor()->getMass();
	result += d.getPowerDistributionBoard()->getMass();
	result += d.getPropeller()->getMass();

	return result;
}
