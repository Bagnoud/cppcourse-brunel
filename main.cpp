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


int main(int argc)	///by default =1
{
	ofstream out("data.txt"); //Output file
	
	long Sim_time_tot(T_Stop/h);	//total time of the simulation
	
	cout << "Current at : " << EXT_CURRENT << "mV" << endl;
	
	
	
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
	
	
	///multi neurons
	
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
				neurons[i].update(time, EXT_CURRENT);	///jupdate juste le premier neurone atm
			} else {
				neurons[i].update(time, 0.0);
			}
		
			out << i << "->" << neurons[i].get_V_mem() << "pA at t=" << time << "ms" << endl;
		}
	}
	

	return 0;
}

