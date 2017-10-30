#ifndef Neuron_H
#define Neuron_H

#include <vector>
#include "Constants.hpp"
#include <fstream>
#include <random>
#include <iostream>

class Neuron
{
	public :
		
		//Constructor
		Neuron ();
		
		Neuron (Type_of_Neuron type);
		
		
		//Destructor
		~Neuron() {};
		
		//Update
			//update the membrane potential, check for spike
			bool update(int time_, double ext_current);
			bool update_TEST(int time_, double ext_current);
			void Compute_V_mem(double J_Buffer_, double ext_current);
			
			//add and incoming current to the buffer
			void plugin_spike(double incoming_spike);
		
		//bool
		bool is_excitatory();
		
		//Getter
		double get_V_mem();
		
		//Google test
		double get_spiked_at();
		long get_nb_spikes();
		
		
		
	private :
		
		double V_mem; //!< Potential of the membrane V
		double tm_spike; //!< Time when last spike
		double tm_spike_at; //!< Time when spike occured
		long nb_spike; //!< Number of spikes
		long local_time; //!< Local time
		std::vector<double> buffer; //!<buffer containing incoming spikes
		
		double C1;	//!< Constants used in membrane potential
		double C2;	//!< Constants used in membrane potential
		
		Type_of_Neuron type_of_neuron;	//!< Defines the type of the neuron (Excitatory of inhibitory)
		
};

#endif
