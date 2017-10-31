#include "Network.hpp"

using namespace std;



/**
 * Constructor
 */
Network::Network ()
  : 
  Nb_excitatory(0.8*Nb_neurons),	//80% of excitatory
  Nb_inhibitory(0.2*Nb_neurons),	//20% of inhibitory
  progress_time(0.25*T_Stop),	//Variables for couting progress
  progress_percentage(25)
{}



/**
 * Creating neurons : filling a vector
 * with all the neurons
 */
void Network::Creating_Neurons()
{
	for(int i(0); i < Nb_excitatory; ++i) {
		Neurons.push_back(Neuron(EXCITATORY));
	}
	
	for(int i(0); i < Nb_inhibitory; ++i) {
		Neurons.push_back(Neuron(INHIBITORY));
	}
}




/**
 * Creating connections : fills a vector of vectors with
 * the list of neurons that each neuron is connected to.
 */
void Network::Creating_Connections()
{
	
	//filling the lines of empty vectors
	for(int i(0); i < Nb_neurons; ++i)
	{
		vector<int> list;
		Connections.push_back(list);
	}
	
	
	//creating random connections for each neuron
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
			Connections[connection_from(gen)].push_back(i);
		}
		
		//10% of inhibitory
		for(int n(0); n < 0.1*Nb_inhibitory; ++n) {
			
			//generating random number in Inhibitory neurons
			static random_device rd;
			static mt19937 gen(rd());
			static uniform_int_distribution<> connection_from(Nb_excitatory, Nb_neurons-1);
			
			//adding a connection from random to i
			Connections[connection_from(gen)].push_back(i);
		}	
	}
}






/**
 * Running simulation : Updates each neurons, prints the spikes.
 */
void Network::Running_Simulation()
{
	//Output file
	ofstream out("data.txt");
	
	
	//running the simulation
	for(long time = 0; time <= T_Stop; ++time)
	{
		//cout the progress for the terminal
		Progress_time(time);
		
		//going through each neuron
		for(size_t i(0); i < Neurons.size(); ++i)
		{
			//updating + checking if one spikes
			if(Neurons[i].update(time, EXT_CURRENT))
			{
				//printing time and neuron that spiked
				out << Neurons[i].get_spiked_at() << "\t" << i << "\n";
				
				//going trough all the connections of neuron i
				for(size_t j(0); j < Connections[i].size(); ++j)
				{
					//checks if the spiking neuron is excitatory
					//and send the signal to the connected neuron
					int connected(Connections[i][j]);
					
					if(Neurons[i].is_excitatory()){
						Neurons[connected].plugin_spike(Je_Spike);
					} else {
						Neurons[connected].plugin_spike(Ji_Spike);
					}
				}
			}
		}
	}
}






/**
 * cout the progress of the program, each 25%.
 * usefull to check if the program is working.
 */
void Network::Progress_time(long time)
{
	//cout the progress for the terminal
	if(time >= progress_time) {
		cout << progress_percentage << "%" << endl;
		progress_percentage += 25;
		progress_time += 0.25*T_Stop;
	}
}





/**
 * Used in Google test, counts the number of connections
 * leading to one neuron, here we test for the 4th neuron
 */
double Network::Count_number_connections(int which_neuron)
{
	double number_of_connections(0);
	
	for(size_t i(0); i < Connections.size(); ++i)
	{
		for(size_t j(0); j < Connections[i].size(); ++j)
		{
			if(Connections[i][j] == which_neuron)
			{
				++number_of_connections;
			}
		}
	}
	
	return number_of_connections;	
}





