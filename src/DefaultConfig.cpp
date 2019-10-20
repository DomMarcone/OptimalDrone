//DefaultConfig.cpp

#include <DefaultConfig.hpp>
#include <AnalyzePermutation.hpp>
#include <Metric/MetricInterface.hpp>
#include <Metric/TotalMass.hpp>

void defaultConfig(AnalyzePermutation &ap){
	
	ap.addMetric(new TotalMass());
	
}