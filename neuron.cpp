#include <iostream>
#include <cmath>
#include "neuron.hpp"
using namespace std;


//Constructeur

Neuron::Neuron ()
	:
	V_mem(0.0),
	tm_spike(0.0),
	nb_spike(0),
	local_time(0),
	C1(0),
	C2(0)
{
	buffer.resize((Delay/h)+1);
}


//Update
bool Neuron::update(int time_, double ext_current)
{
	//we update as the time of the main program
	local_time = time_;
	
	//incoming spike to be added
	double J(0.0);
	
	
	//checks if a spike need to be added to the membrane potential
	if (buffer[local_time % buffer.size()] > 0)
	{
		//redefinition of J, to be added
		J = buffer[local_time % buffer.size()];
		//cleaning of the buffer 
		buffer[local_time % buffer.size()] = 0.0;
	}
	
	
	///Updating membrane potential
	
	//checks if refractory period
	if (tm_spike > 0) {
		--tm_spike;
	
	//Membrane potential evolving according to formula	
	} else {
		//membrane potential doesnt go into negatives
		if (V_mem >= 0.0)
		{
			C1 = exp(-h/TAU)*V_mem;
			C2 = R*(1-exp(-h/TAU));
			
			//updating membrane potential (+ J if additional spike)
			V_mem = C1 + ext_current*C2 + J;
		}
	}

	//checks if spike occuring
	if (V_mem >= V_THR)
	{	
		V_mem = 0.0; //reset membrane potential to 0
		tm_spike = T_REFR; //sets refractory period
		++nb_spike;	//register one spike
		
		///for terminal
		cout << "Spike at t=" << local_time*h << "ms" << endl;
		
		//we have a spike
		return true;
	}
	
	//no spike has occured, by default
	return false;
}




void Neuron::plugin_spike()
{
	//add in the buffer 
	buffer[local_time % (buffer.size())] += J_Spike;
}





//Getter

double Neuron::get_V_mem()
{
	return V_mem;
}






