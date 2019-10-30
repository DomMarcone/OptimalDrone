//StaticThrust.hpp
#pragma once

#ifndef _STATICTHRUST_HPP
#define _STATICTHRUST_HPP

#include <Metric/MetricInterface.hpp>
#include <Drone.hpp>

class StaticThrust : public MetricInterface {
private :
public :
	StaticThrust();

	float calculate(Drone &d);
};

#endif //_STATICTHRUST_HPP
