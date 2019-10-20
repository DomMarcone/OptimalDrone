//Motor.cpp

#include <Part/PartInterface.hpp>
#include <Part/PartTypes.h>
#include <Part/Motor.hpp>

#include <string>

using namespace std;

Motor::Motor(){
	setType(MOTOR_FLAG);
}

Motor::Motor(string name, float mass, float cost, float statorDiameter, float magnetHeight, float kv){
	this->statorDiameter = statorDiameter;
	this->magnetHeight = magnetHeight;
	this->kv = kv;
	
	setName(name);
	setMass(mass);
	setCost(cost);
	setType(MOTOR_FLAG);
}

void Motor::setMotorSize(float statorDiameter, float magnetHeight){
	this->statorDiameter = statorDiameter;
	this->magnetHeight = magnetHeight;
}

void Motor::setStatorDiameter(float statorDiameter){	this->statorDiameter = statorDiameter;	}
void Motor::setMagnetHeight(float magnetHeight){		this->magnetHeight = magnetHeight;	}
void Motor::setKV(float kv){							this->kv = kv;	}

float Motor::getStatorDiameter(){	return this->statorDiameter;	}
float Motor::getMagnetHeight(){	return this->magnetHeight;	}
float Motor::getKV(){	return this->kv;	}

