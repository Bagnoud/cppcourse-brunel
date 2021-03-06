#ifndef Network_H
#define Network_H

#include "neuron.hpp"
using namespace std;


class Network
{
	public :
	
		Network();
		
		~Network() {};
	
		void Creating_Neurons();
		
		void Creating_Connections();
		
		void Running_Simulation();
		
		//Google Tests
		double Count_number_connections(int which_neuron);
		
	
	private :
	
		void Progress_time(long time);	//!< Variable used for progress of the program
	
		const int Nb_excitatory;	//!< Number of excitatory neurons
		const int Nb_inhibitory;	//!< Number of inhibitory neurons
		
		int progress_time;	//!< variable for user interface
		int progress_percentage;	//!< variable for user interface
	
		vector<Neuron> Neurons;		//!< list of the neurons
		vector<vector<int>> Connections;	//!< list of the connections
	
};

#endif
