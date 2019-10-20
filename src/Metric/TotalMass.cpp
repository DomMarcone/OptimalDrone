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

#include <Metric/utils.hpp>

TotalMass::TotalMass(){
	setName("mass");
}

float TotalMass::calculate(Drone &d){
	return getMass(d);
}
