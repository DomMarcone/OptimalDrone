//DefaultConfig.cpp

#include <DefaultConfig.hpp>
#include <AnalyzePermutation.hpp>
#include <Metric/MetricInterface.hpp>

#include <Metric/TotalMass.hpp>
#include <Metric/TotalCost.hpp>
#include <Metric/StaticThrust.hpp>

void defaultConfig(AnalyzePermutation &ap){

	ap.addMetric(new TotalMass());
	ap.addMetric(new TotalCost());
	ap.addMetric(new StaticThrust());

}
