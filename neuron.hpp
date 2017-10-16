#ifndef Neuron_H
#define Neuron_H

#include <vector>

class Neuron
{
	public :
		
		//Constructor
		Neuron ();
		
		//Destructor
		~Neuron() {};
		
		//Update
			//update the membrane potential, check for spike
			bool update(int time_, double ext_current);
			
			//add and incoming current to the buffer
			void plugin_spike();
		
		//Getter
		double get_V_mem();
		
	private :
		
		double V_mem; // Potential of the membrane V
		//double I_ext; /// External current
		double tm_spike; // Time when last spike
		long nb_spike; // Number of spikes
		long local_time; // Local time
		std::vector<double> buffer; //buffer containing incoming spikes
		

		// Constants	//to be added in a external file
		const double R = 20.0; // Resistance membrane
		const double TAU = 20.0; /// Membrane time constant
		const double V_THR = 20.0; // Threshold
		const double T_REFR = 2.0; // Refractory time
		const double H = 0.1; // Step time
		const double Delay = 1.5; //Delay of spike
		const double J_Spike = 0.1; //mV spike sent
			
};

#endif
