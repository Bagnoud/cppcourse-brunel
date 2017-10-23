#ifndef Neuron_H
#define Neuron_H

//#include <vector>
#include "Constants.hpp"
#include <random>

class Neuron
{
	public :
		
		//Constructor
		Neuron ();
		
		Neuron (Type_of_Neuron type);
		
		///nouveau constructeur avec type ?
		
		//Destructor
		~Neuron() {};
		
		//Update
			//update the membrane potential, check for spike
			bool update(int time_, double ext_current);
			void Compute_V_mem(double J_Buffer_);
			
			//add and incoming current to the buffer
			void plugin_spike();
		
		//Getter
		double get_V_mem();
		
	private :
		
		double V_mem; // Potential of the membrane V
		double tm_spike; // Time when last spike
		long nb_spike; // Number of spikes
		long local_time; // Local time
		std::vector<double> buffer; //buffer containing incoming spikes
		
		//constants used in membrane potential
		double C1;
		double C2;
		
		Type_of_Neuron type_of_neuron;
		
};

#endif
