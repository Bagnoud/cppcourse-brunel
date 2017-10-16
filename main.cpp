#include <iostream>
#include <fstream>
#include "neuron.hpp"
#include <vector>
//#include "Constants.hpp"
using namespace std;

///Also in external file
int T_Stop(5000);
double h(0.1);	//step time
int Current_Start(1000);
int Current_Stop(4000);

double EXT_CURRENT(1.01);
//double Delay(1.5);	//defined in neuron.hpp
//double J_Spike(0.1);


int main(int argc)	///by default =1
{
	ofstream out("data.txt"); //Output file
	
	long Sim_time_tot(T_Stop/h);	//total time of the simulation
	
	cout << "Current at : " << EXT_CURRENT << "mV" << endl;
	//add a function to change when calling the program, check if 
	//higher than 1.01
	
	
	
///One neuron only
/*
	Neuron neuron;
	//Simulation
	for (long time = 0; time <= T_Stop; ++time)	/// to remove
	{
		
			if ((time > Current_Start) and (time < Current_Stop))
			{
				neuron.update(time, EXT_CURRENT);
			} else {
				neuron.update(time, 0.0);
			}
		
			out << neuron.get_V_mem() << "pA at t=" << time*h << "ms" << endl;
	}
*/
	
	
///two neurons
	
	vector<Neuron> neurons; //Construction of a neuron
	Neuron n1;
	Neuron n2;
	neurons.push_back(n1);
	neurons.push_back(n2);
	
	//Simulation
	for (long time = 0; time <= T_Stop; ++time)
	{
		if ((time > Current_Start) and (time < Current_Stop))
		{
			if (neurons[0].update(time, EXT_CURRENT)) {	//only the first gets current here
				neurons[1].plugin_spike();	//spike has occured, we pass the spike to the other
			}
			
			neurons[1].update(time, 0.0);	//the second one doesnt get current
			
		} else {
			neurons[0].update(time, 0.0);
			neurons[1].update(time, 0.0);
		}
		
			out << 1 << "->" << neurons[0].get_V_mem() << "pA at t=" << time*h << "ms" << "\t"
			<< 2 << "->" << neurons[1].get_V_mem() << "pA at t=" << time*h << "ms" << endl;
		}
	
	
	
///multi neurons
/*	
	vector<Neuron> neurons; //Construction of a neuron
	Neuron n1;
	Neuron n2;
	neurons.push_back(n1);
	neurons.push_back(n2);
	
	//Simulation
	for (long time = 0; time <= T_Stop; ++time)
	{
		for (size_t i(0); i < neurons.size(); ++ i)
		{
			if ((time > Current_Start) and (time < Current_Stop))
			{
				neurons[0].update(time, EXT_CURRENT);	///jupdate juste le premier neurone atm
			} else {
				neurons[0].update(time, 0.0);
			}
		
			out << i << "->" << neurons[i].get_V_mem() << "pA at t=" << time*h << "ms" << endl;
		}
	}
*/	

	return 0;
}

