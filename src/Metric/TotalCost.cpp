//TotalCost.cpp

#include <Metric/MetricInterface.hpp>
#include <Metric/TotalCost.hpp>

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

TotalCost::TotalCost(){
	setName("cost");
}

float TotalCost::calculate(Drone &d){
	float result = 0.f;
	
	result += d.getFlightController()->getCost();
	result += d.getElectronicSpeedController()->getCost();
	result += d.getBattery()->getCost();
	result += d.getFrame()->getCost();
	result += d.getMotor()->getCost();
	result += d.getPowerDistributionBoard()->getCost();
	result += d.getPropeller()->getCost();

	return result;
}
