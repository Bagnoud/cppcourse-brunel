#ifndef Neuron_H
#define Neuron_H

class Neuron
{
	public :
		
		//Constructor
		Neuron ();
		
		//Destructor
		~Neuron() {};
		
		//Update
		void update(int time_, double ext_current);	///bool spike oui ou non /// avec nb de steps
		
		//Getter
		double get_V_mem();
		
	private :
		
		double V_mem; // Potential of the membrane V
		double I_ext; /// External current
		double tm_spike; // Time when last spike
		long nb_spike; // Number of spikes
		long local_time; /// Local time
		
		
		// Constants	//to be added in a external file
		const double R = 20.0; // Resistance membrane
		const double TAU = 20.0; /// Membrane time constant
		const double V_THR = 20.0; // Threshold
		const double T_REFR = 2.0; // Refractory time
		const double H = 0.1; // Step time
		//const long REFR_STEPS; /// Steps per T_REFR 
		
		
};

#endif
