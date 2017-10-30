#include <iostream>
#include <fstream>
#include "neuron.hpp"
#include <vector>
using namespace std;


int main()
{
	
	//Output file
	ofstream out("data.txt");

	
	//construction des Neurones
	const int Nb_excitatory = 0.8 * Nb_neurons;	//80% of excitatory
	const int Nb_inhibitory = 0.2 * Nb_neurons;	//20% of inhibitory
	
	
	
	//-----------------------------------------------------------------
	cout << "Creating Neurons" << endl;
	
	vector<Neuron> Neurons;
	
	for(int i(0); i < Nb_excitatory; ++i) {
		Neurons.push_back(Neuron(EXCITATORY));
	}
	
	for(size_t i(Nb_excitatory); i < Neurons.size(); ++i) {
		Neurons.push_back(Neuron(INHIBITORY));
	}

	
	
	
	//-----------------------------------------------------------------
	cout << "Establishing connections" << endl;
	
	vector<vector<int>> Network;
	
	for(int i(0); i < Nb_neurons; ++i)
	{
		vector<int> list;
		Network.push_back(list);
	}
	
	
	//boucle sur chaque neurone pour lui trouver ses connections
	for(int i(0); i < Nb_neurons; ++i)
	{
		//10% of excitatory neurons
		for(int n(0); n < 0.1*Nb_excitatory; ++n)
		{
			//generating random number in Excitatory neurons
			static random_device rd;
			static mt19937 gen(rd());
			static uniform_int_distribution<> connection_from(0, Nb_excitatory-1);
			
			//adding a connection from random to i
			Network[connection_from(gen)].push_back(i);
		}
		
		//10% of inhibitory
		for(int n(0); n < 0.1*Nb_inhibitory; ++n) {
			
			//generating random number in Excitatory neurons
			static random_device rd;
			static mt19937 gen(rd());
			static uniform_int_distribution<> connection_from(Nb_excitatory, Nb_neurons-1);
			
			//adding a connection from random to i
			Network[connection_from(gen)].push_back(i);
		}	
	}
	

	
	
		
	//-----------------------------------------------------------------		
	cout << "Running the simulation" << endl;
	
	
	
	int progress_time(0.25*T_Stop);
	int progress_percentage(25);
	
	
	//running the simulation
	for(long time = 0; time <= T_Stop; ++time)
	{
		//cout the progress for the terminal
		if(time >= progress_time) {
			cout << progress_percentage << "%" << endl;
			progress_percentage += 25;
			progress_time += 0.25*T_Stop;
		}
		
		
		//going through each neuron
		for(size_t i(0); i < Neurons.size(); ++i)
		{
			//updating + checking if one spikes
			if(Neurons[i].update(time, EXT_CURRENT))
			{
				//going trough all the connections of neuron i
				for(size_t j(0); j < Network[i].size(); ++j)
				{
					//checks if the spiking neuron is excitatory
					//and send the signal to the connected neuron
					if(Neurons[i].is_excitatory()){
						Neurons[j].plugin_spike(Je_Spike);
					} else {
						Neurons[j].plugin_spike(Ji_Spike);
					}
				}
			}
		}			
		
		out << time << "	" << Neurons[0].get_V_mem() << endl;
	}

	

	cout << "Simulation done" << endl;
	return 0;
}

//top graph
//rescale with ms 
/// spike_time << "\t" << neuron _id << "\n";

//under graph
/// 

///checker avec assert pour voir le segfault
///#include <cassert>

//doxygen cmake intergration -> google










