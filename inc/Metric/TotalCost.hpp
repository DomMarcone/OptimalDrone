//TotalCost.hpp
#pragma once

#ifndef _TOTALCOST_HPP
#define _TOTALCOST_HPP

#include <Metric/MetricInterface.hpp>
#include <Drone.hpp>

class TotalCost : public MetricInterface {
private :
public :
	TotalCost();
	
	float calculate(Drone &d);
};

#endif //_TOTALCOST_HPP
