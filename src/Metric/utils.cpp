//utils.cpp

#include <Metric/utils.hpp>

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

#include <cmath>


#define UTILS_PI 3.14159265359f

#define UTILS_GUESSED_PROP_EFFICIENCY 0.6f
#define UTILS_GUESSED_ELEC_EFFICIENCY 0.95f

#define UTILS_AIR_DENSITY 1.225f // kg/m3

#define UTILS_METERS_PER_INCH 0.0254f;

inline float inchToMeter(float i){	return i * UTILS_METERS_PER_INCH;	}

float getMass(Drone& d){
	float result = d.getFlightController()->getMass();
	result += d.getElectronicSpeedController()->getMass();
	result += d.getBattery()->getMass();
	result += d.getFrame()->getMass();
	result += d.getMotor()->getMass();
	result += d.getPowerDistributionBoard()->getMass();
	result += d.getPropeller()->getMass();

	return result;
}

float getMotorPower(Drone& d){
	return 1.0;//TODO
}

float getStaticThrust(Drone& d){
	//Based off of the equations in https://aviation.stackexchange.com/a/8822
	float efficiency = UTILS_GUESSED_PROP_EFFICIENCY * sinf( d.getPropeller()->getPitch() );

	float inside_cuberoot =
		pow( getMotorPower(d), 2.0 ) *
		pow( efficiency, 2.0 ) *
		pow( efficiency, 2.0 ) *
		( pow(inchToMeter(
				d.getPropeller()->getPropSize()
			),2.0)/2.f ) *
		UTILS_AIR_DENSITY;

	return (float)pow(inside_cuberoot, 0.333);
}
