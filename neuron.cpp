#include <iostream>
#include <cmath>
#include "neuron.hpp"
//#include "Constants.hpp"
using namespace std;


//Constructeur

Neuron::Neuron ()
	:
	V_mem(0.0),
	//I_ext(0.0),
	tm_spike(0.0),
	nb_spike(0),
	local_time(0)
{
	buffer.resize((Delay/H)+1);
}


//Update

///BOUGE DANS LE BUFFER ! TAS OUBLIé

bool Neuron::update(int time_, double ext_current)	///add the local time, accordingly to the main
{
	local_time = time_;	//we update as the time of the main program
	
	//checker si dans tableau y'a un J présent ou pas
	double J(0.0);	//incoming spike to be added
	
	if (buffer[local_time % buffer.size()] > 0) //a spike need to be added to the membrane potential
	{
		J = buffer[local_time % buffer.size()];	//redefinition of J, to be added 
		buffer[local_time % buffer.size()] = 0.0; //cleaning of the buffer 
	}
	
	
	//Updating membrane potential
	if (tm_spike > 0) { //refractory period ?
		--tm_spike;
		
	} else {	//Membrane potential evolving according to formula
		if (V_mem >= 0.0){	//doesnt go into negatives
			V_mem = exp(-H/TAU)*V_mem + ext_current*R*(1-exp(-H/TAU)) + J;
		}
	}

	//Spike occuring ?
	if (V_mem >= V_THR)
	{	
		V_mem = 0.0; //reset membrane potential to 0
		tm_spike = T_REFR; //refractory period
		++nb_spike;	//register one spike
		
		///send output current
		
		cout << "Spike at t=" << local_time*H << "ms" << endl;
		
		return true;	//we have a spike
	}
	
	return false;	//no spike has occured, by default
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






