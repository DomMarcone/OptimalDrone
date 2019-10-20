//AnalyzePermutation.hpp
#pragma once

#ifndef _ANALYZEPERMUTATION_HPP
#define _ANALYZEPERMUTATION_HPP

#include <vector>

#include <Metric/MetricInterface.hpp>
#include <Drone.hpp>

using namespace std;

class AnalyzePermutation{
private:
	
	vector<MetricInterface *> metrics;
	
public:
	
	void addMetric(MetricInterface *m);
	void removeMetric(MetricInterface *m);
	
	void analyze(Drone& d);
};

#endif //_ANALYZEPERMUTATION_HPP