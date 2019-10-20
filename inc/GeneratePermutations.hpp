//GeneratePermutations.hpp
#pragma once

#ifndef _GENERATEPERMUTATIONS_HPP
#define _GENERATEPERMUTATIONS_HPP

#include <Part/PartInterface.hpp>
#include <AnalyzePermutation.hpp>
#include <Drone.hpp>

#include <vector>
#include <string>

using namespace std;

void generatePermutations(vector<Kit*>& pv, int start, Drone& drone, AnalyzePermutation& ap);

#endif //_GENERATEPERMUTATIONS_HPP
