//MetricInterface.cpp

#include <Metric/MetricInterface.hpp>
#include <Drone.hpp>
#include <string>

using namespace std;

void MetricInterface::setName(string n){	this->name = n;	}
string MetricInterface::getName(){	return this->name;	}

float MetricInterface::calculate(Drone &d){	return 0.f;	}
