#include <iostream>
#include <fstream>
#include "neuron.hpp"
#include <array>
using namespace std;




int main()	///by default =1
{
	
	//Output file
	ofstream out("data.txt");
	
	
	//total time of the simulation
	long Sim_time_tot(T_Stop/h);
	
	//for terminal
	cout << "Current at : " << EXT_CURRENT << "mV" << endl;
	//add a function to change when calling the program, check if 
	//higher than 1.01
	
	
	
///One neuron only
/*
	Neuron neuron;
	//Simulation
	for (long time = 0; time <= T_Stop; ++time)	/// to remove
	{
		
		if ((time > Current_Start) and (time < Current_Stop))
		{
			neuron.update(time, EXT_CURRENT);
		} else {
			neuron.update(time, 0.0);
		}
		
		out << neuron.get_V_mem() << "pA at t=" << time*h << "ms" << endl;
	}
*/
	
	
///two neurons
/*	
	vector<Neuron> neurons; //Construction of a neuron
	Neuron n1;
	Neuron n2;
	neurons.push_back(n1);
	neurons.push_back(n2);
	
	//Simulation time
	for (long time = 0; time <= T_Stop; ++time)
	{
		//checks if there is current or not
		if ((time > Current_Start) and (time < Current_Stop))
		{
			//only the first gets current here
			if (neurons[0].update(time, EXT_CURRENT)) {
				//spike has occured, we pass the spike to the other
				neurons[1].plugin_spike();
			}
			
			//the second one doesnt get current in this simulation
			neurons[1].update(time, 0.0);
		
		//out of the times with current, no current is given	
		} else {
			neurons[0].update(time, 0.0);
			neurons[1].update(time, 0.0);
		}

		//printing in file
		out << 1 << "->" << neurons[0].get_V_mem() << "pA at t=" << time*h << "ms" << "\t" << "\t"
			<< 2 << "->" << neurons[1].get_V_mem() << "pA at t=" << time*h << "ms" << endl;
	}
*/	
	
	
///multi neurons
	
	//construction des Neurones
	const int Total_Nb_Neurons(Nb_excitatory + Nb_inhibitory);
	
	cout << "Creating Neurons" << endl;
	
	array<Neuron, Total_Nb_Neurons> Neurons;
	
	for(int i(0); i < Nb_excitatory; ++i) {
		Neurons[i] = Neuron(EXCITATORY);
	}
	
	for(size_t i(Nb_excitatory); i < Neurons.size(); ++i) {
		Neurons[i] = Neuron(INHIBITORY);
	}
	
	
	cout << "Establishing connections" << endl;
	
	//list of connections
	array<array<int,Total_Nb_Neurons>, Total_Nb_Neurons> Network;
	
	//Initialisation of each case to 0 in Network array
	for (size_t i(0); i < Network.size(); ++i) {
		for (size_t j(0); j < Network.size(); ++j) {
			Network[i][j] = 0;
		}
	}

	//Establishing connections
	
	//go through all the columns
	//each neurons recieves 10% connection of all the neurons
	for (size_t j(0); j < Network.size(); ++j){
		
		//10% of excitatory
		for (int n(0); n < 0.1*Nb_excitatory; ++n) {
			
			//generating random number in Excitatory neurons
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> connection_from(0, Nb_excitatory-1);
			
			//adding a connection
			Network[connection_from(gen)][j] += 1;
		}
		
		//10% of inhibitory
		for (int n(0); n < 0.1*Nb_inhibitory; ++n) {
			
			//generating random number in Excitatory neurons
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> connection_from(Nb_excitatory, Total_Nb_Neurons-1);
			
			//adding a connection
			Network[connection_from(gen)][j] += 1;
		}
	}
			
	cout << "Running the simulation" << endl;
	

	
	

	return 0;
}





















