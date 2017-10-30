#include <iostream>
#include "neuron.hpp"
#include "Network.hpp"
#include <vector>
using namespace std;


int main()
{
	Network simulation;

	//-----------------------------------------------------------------
	cout << "Creating Neurons" << endl;
	
	simulation.Creating_Neurons();

	//-----------------------------------------------------------------
	cout << "Establishing connections" << endl;
	
	simulation.Creating_Connections();
		
	//-----------------------------------------------------------------		
	cout << "Running the simulation" << endl;
	
	simulation.Running_Simulation();
	
	//-----------------------------------------------------------------
	cout << "Simulation done" << endl;
	return 0;
}

//doxygen cmake intergration -> google
