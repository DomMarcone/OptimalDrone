//DefaultConfig.cpp

#include <DefaultConfig.hpp>
#include <AnalyzePermutation.hpp>
#include <Metric/MetricInterface.hpp>

#include <Metric/TotalMass.hpp>
#include <Metric/TotalCost.hpp>

void defaultConfig(AnalyzePermutation &ap){
	
	ap.addMetric(new TotalMass());
	ap.addMetric(new TotalCost());
	
}