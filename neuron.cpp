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

Neuron::Neuron (Type_of_Neuron type)
	:
	V_mem(0.0),
	tm_spike(0.0),
	nb_spike(0),
	local_time(0),
	C1(0),
	C2(0)
{
	buffer.resize((Delay/h)+1);
	
	if (type == EXCITATORY) {
		type_of_neuron = EXCITATORY;
	} else {
		type_of_neuron = INHIBITORY;
	}
}


//Update
bool Neuron::update(int time_, double ext_current)
{
	//we update as the time of the main program
	local_time = time_;
	
	//incoming spike to be added
	double J_buffer(0.0);
	
	
	//checks if a spike need to be added to the membrane potential
	if (buffer[local_time % buffer.size()] > 0)
	{
		//redefinition of J, to be added
		J_buffer = buffer[local_time % buffer.size()];
		//cleaning of the buffer 
		buffer[local_time % buffer.size()] = 0.0;
	}
	
	
	///Updating membrane potential
	
	//checks if refractory period
	if (tm_spike > 0) {
		--tm_spike;
		
	} else {
		
		if (V_mem >= 0.0) { //membrane potential doesnt go into negatives
			Compute_V_mem(J_buffer);
		}
	}


	///checks if spike occuring 

	if (V_mem >= V_THR)
	{	
		V_mem = 0.0; //reset membrane potential to 0
		tm_spike = T_REFR; //sets refractory period
		++nb_spike;	//register one spike

		//we have a spike
		return true;
	}
	
	//no spike has occured, by default
	return false;
}




void Neuron::Compute_V_mem(double J_Buffer_)
{
	///Je spike ? ou J dépendant du type ?
	//déclaration de la distribution
	poisson_distribution<> poisson(Vext*0.1*Nb_excitatory*h*Je_Spike);
	random_device rd;
	mt19937 gen(rd());
			
	C1 = exp(-h/TAU)*V_mem;
	C2 = R*(1-exp(-h/TAU));
			
	//updating membrane potential (+ J if additional spike)
	V_mem = C1 + J_Buffer_ + poisson(gen);
	
	///+ ext_current*C2
}






///différentier E ou I
void Neuron::plugin_spike()
{
	//add in the buffer 
	buffer[local_time % (buffer.size())] += Je_Spike;
}





//Getter

double Neuron::get_V_mem()
{
	return V_mem;
}






