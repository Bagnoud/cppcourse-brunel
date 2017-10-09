#include <iostream>
#include <cmath>
#include "neuron.hpp"
//#include "Constants.hpp"
using namespace std;


//Constructeur

Neuron::Neuron ()
	:
	V_mem(0.0),
	I_ext(0.0),
	tm_spike(0.0),
	nb_spike(0),
	local_time(0)
{}


//Update

void Neuron::update(int time_, double ext_current)
{
	if (tm_spike > 0) { //refractory period ?
		--tm_spike;
		
	} else {	//Membrane potential evolving according to formula
		if (V_mem >= 0.0){	//doesnt go into negatives
			double h(0.1);	///
			V_mem = exp(-h/TAU)*V_mem + ext_current*R*(1-exp(-h/TAU));
		}
	}


	if (V_mem >= V_THR) //Spike occuring ?
	{	
		V_mem = 0.0; //reset membrane potential to 0
		tm_spike = T_REFR; //refractory period
		++nb_spike;	//register one spike
		
		///send output current
		
		cout << "Spike at t=" << time_ << "ms" << endl;
	}
}


//Getter

double Neuron::get_V_mem()
{
	return V_mem;
}






