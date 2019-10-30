//TotalMass.hpp
#pragma once

#ifndef _TOTALMASS_HPP
#define _TOTALMASS_HPP

#include <Metric/MetricInterface.hpp>
#include <Drone.hpp>

class TotalMass : public MetricInterface {
private :
public :
	TotalMass();

	float calculate(Drone &d);
};

#endif //_TOTALMASS_HPP
