//TestPopulate.cpp

#include <Part/PartTypes.h>
#include <Part/PartInterface.hpp>

#include <Part/FlightController.hpp>
#include <Part/ElectronicSpeedController.hpp>
#include <Part/Battery.hpp>
#include <Part/Frame.hpp>
#include <Part/Motor.hpp>
#include <Part/PowerDistributionBoard.hpp>
#include <Part/Propeller.hpp>
#include <Part/Kit.hpp>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//this will be a long function
void populate_vector( vector<PartInterface*>& pv ){

	//FlightController(string name, float mass, float cost, string firmware, string processor);
	pv.push_back( 
		new FlightController("FlightController name", 1.f, 19.99f, "BetaFlight4", "F7"));
	pv.push_back(
		new FlightController("SuperSmart3 - dronestorenonsense.com", 0.1f, 65.00f, "BetaFlight3", "F4"));
	pv.push_back(
		new FlightController("DroneBrain - quadstore.com", 0.075f, 50.00f, "KISS", "F7"));
	
	//ElectronicSpeedController(string name, float mass, float cost, float amps, string firmware, string protocol);
	pv.push_back(
		new ElectronicSpeedController("ElectronicSpeedController", 0.05f, 19.99f, 10.f, "esc firmware", "esc protocol"));
	
	//Battery(string name, float mass, float cost, float mWattHours, float voltage, float cRating);
	pv.push_back(
		new Battery("Battery", 0.1f, 19.99f, 1300.f, 12.f, 10.f));
	
	//Frame(string name, float mass, float cost, unsigned short prop_size);
	pv.push_back(new Frame("Frame", 0.025f, 39.99f, 4));
	
	//Motor(string name, float mass, float cost, float statorDiameter, float magnetHeight, float kv);
	pv.push_back(
		new Motor("Motor", 0.1f, 39.99f, 10.f, 20.f, 40.f));
		
	//PowerDistributionBoard(string name, float mass, float cost, float maxAmps);
	pv.push_back(
		new PowerDistributionBoard("PDB", 0.05f, 39.99f, 100.f));
	
	//Propeller(string name, float mass, float cost, unsigned short propSize, float propPitch, unsigned short blades);
	pv.push_back(
		new Propeller("Propeller", 0.01f, 1.99f, 4, 40.f, 2));

	
}

int main(){
	std::vector<PartInterface*> partVector;
	
	populate_vector(partVector);
	
	cout << "Done." << endl;

	return 0;
}
