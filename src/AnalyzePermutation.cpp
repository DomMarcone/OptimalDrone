//AnalyzePermutation.hpp

#include <Metric/MetricInterface.hpp>
#include <AnalyzePermutation.hpp>
#include <Drone.hpp>

#include <vector>
#include <iostream>
#include <string>

using namespace std;

void AnalyzePermutation::analyze(Drone& d){
	cout << d.getFlightController()->getName() << "\t";
	cout << d.getElectronicSpeedController()->getName() << "\t";
	cout << d.getBattery()->getName() << "\t";
	cout << d.getFrame()->getName() << "\t";
	cout << d.getMotor()->getName() << "\t";
	cout << d.getPowerDistributionBoard()->getName() << "\t";
	cout << d.getPropeller()->getName() << endl;
}

void AnalyzePermutation::addMetric(MetricInterface *m){
	this->metrics.push_back(m);
}

void AnalyzePermutation::removeMetric(MetricInterface *m){
	vector<MetricInterface*>::itterator loc;
	
	loc = find(metrics.begin(), metrics.end(), m);
	
	if(loc != metrics.end()){
		metrics.erase(loc);
	}
}
