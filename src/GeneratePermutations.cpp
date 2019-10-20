//GeneratePermutations.cpp

#include <Part/PartInterface.hpp>
#include <GeneratePermutations.hpp>
#include <AnalyzePermutation.hpp>
#include <Drone.hpp>

#include <vector>
#include <string>

using namespace std;

void generatePermutations(vector<Kit*>& pv, int start, Drone& drone, AnalyzePermutation& ap){
	if(drone.isComplete()){
		ap.analyze(drone);
		return;
	}
	
	if(start >= pv.size())return;
	
	//Drone is incomplete and parts are left in the vector
	
	for(int i=start; i<pv.size(); ++i){
		if(drone.isAddable(pv[i])){
			drone.addPart(pv[i]);
			generatePermutations(pv, i+1, drone, ap);
			drone.removePart(pv[i]);
		}
	}
}

