//Motor.hpp
#pragma once

#ifndef _MOTOR_HPP
#define _MOTOR_HPP

#include <Part/PartInterface.hpp>

#include <string>

using namespace std;

class Motor : public PartInterface {
private :
	float statorDiameter;
	float magnetHeight;
	
	float kv;
	
public :
	
	Motor();
	
	Motor(string name, float mass, float cost, float statorDiameter, float magnetHeight, float kv);
	
	void setMotorSize(float stator_diameter, float magnetHeight);
	void setStatorDiameter(float statorDiameter);
	void setMagnetHeight(float magnetHeight);
	void setKV(float kv);
	
	float getStatorDiameter();
	float getMagnetHeight();
	float getKV();
	
};

#endif //_MOTOR_HPP
