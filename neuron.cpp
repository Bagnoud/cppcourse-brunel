#include <iostream>
#include <cmath>
#include "neuron.hpp"
using namespace std;



/**
 * Default constructor
 */
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




/**
 * Constructor
 * @param type : type of the neuron (excitatory of inhibitory)
 */
Neuron::Neuron (Type_of_Neuron type)
	:
	V_mem(0.0),
	tm_spike(0.0),
	nb_spike(0),
	local_time(0),
	C1(0),
	C2(0),
	type_of_neuron(type)
{
	buffer.resize((Delay/h)+1);
}






/**
 * Update of the neuron
 * @param time_ : time of the simulation
 * @param ext_current : external current
 * @return true : if the neuron spiked
 * @return false : if the neuron didn't spiked
 */
bool Neuron::update(int time_, double ext_current)
{
	//we take the same time of the main program
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
	
	
	
	//Updating membrane potential
	
	//checks if refractory period
	if (tm_spike > 0) {
		--tm_spike;
		
	//we are not in a refractory period -> we update 
	} else {
		
		if (V_mem >= 0.0) { //membrane potential doesnt go into negatives
			Compute_V_mem(J_buffer, ext_current);
		}
	}


	//checks if spike occuring
	
	if (V_mem >= V_THR)
	{	
		V_mem = 0.0; //reset membrane potential to 0
		tm_spike = T_REFR; //sets refractory period
		++nb_spike;	//register one spike
		tm_spike_at = time_; //writes when the spike occured

		//we have a spike
		return true;
	}
	
	//no spike has occured, by default
	return false;
}







/**
 * Compute the membrane potential
 * @param J_Buffer_ : potential to be added which was in the buffer
 * @param ext_current : external current
 */
void Neuron::Compute_V_mem(double J_Buffer_, double ext_current)
{
	//Declaration of the Poisson distribution
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> poisson(Lambda);
	
	//we don't want negative external current
	if (ext_current < 0) { ext_current = 0; }
			
	C1 = exp(-h/TAU)*V_mem;
	C2 = R*(1-exp(-h/TAU));
	
	double added_potential(J_Buffer_ + J_ext*poisson(gen));
			
	//updating membrane potential (+ added_potential if additional spike)
	V_mem = C1 + ext_current*C2 + added_potential;
}






/**
 * Takes an incoming spike and adds it in the buffer
 * @param incoming_spike : value of the incoming spike
 */
void Neuron::plugin_spike(double incoming_spike)
{
	//adds in the buffer 
	buffer[local_time % (buffer.size())] += incoming_spike;
}






/**
 * Checks if the neuron is excitatory
 * @return true : neuron is excitatory
 * @return false : neuron is inhibitory
 */
bool Neuron::is_excitatory()
{
	if (type_of_neuron == EXCITATORY) {
		return true;
	} else {
		return false;
	}
}





/**
 * Getter for membrane potential
 * @return membrane Potential
 */
double Neuron::get_V_mem()
{
	return V_mem;
}




/**
 * Return the time when the spike occured in the neuron
 * @return tm_spike_at : time when spiked
 */
double Neuron::get_spiked_at()
{
	return tm_spike_at;
}





/**
 * Same function as update, but without a random factor.
 * Used for the google tests.
 * @return true : if the neuron spiked
 * @return false : if the neuron didn't spiked
 */
bool Neuron::update_TEST(int time_, double ext_current)
{
	//we take the same time of the main program
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
	
	
	//Updating membrane potential
	
	//checks if refractory period
	if (tm_spike > 0) {
		--tm_spike;
		
	//we are not in a refractory period -> we update 
	} else {
		if (V_mem >= 0.0) { //membrane potential doesnt go into negatives
			//we don't want negative currents
			if (ext_current < 0) { ext_current = 0; }
			
			C1 = exp(-h/TAU)*V_mem;
			C2 = R*(1-exp(-h/TAU));
	
			double added_potential(J_buffer);
			
			//updating membrane potential (+ added_potential if additional spike)
			V_mem = C1 + ext_current*C2 + added_potential;
		}
	}


	//checks if spike occuring
	if (V_mem >= V_THR)
	{	
		V_mem = 0.0; //reset membrane potential to 0
		tm_spike = T_REFR; //sets refractory period
		++nb_spike;	//register one spike
		tm_spike_at = time_;

		//we have a spike
		return true;
	}
	
	//no spike has occured, by default
	return false;
}






/**
 * Returns the number of spike that the neuron had
 * @return nb_spike : number of spikes
 */
long Neuron::get_nb_spikes()
{
	return nb_spike;
}



