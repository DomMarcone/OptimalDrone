//MetricInterface.hpp
#pragma once

#ifndef _METRICINTERFACE_HPP
#define _METRICINTERFACE_HPP

#include <Drone.hpp>
#include <string>

using namespace std;

class MetricInterface{
private :
	string name;
	
public :
	
	void setName(string n);
	string getName();
	
	//get some measurable/calculatable metric
	virtual float calculate(Drone &d);
};

#endif //_METRICINTERFACE_HPP
