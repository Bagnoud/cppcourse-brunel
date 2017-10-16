#include <iostream>
#include <fstream>
#include "neuron.hpp"
using namespace std;




int main()	///by default =1
{
	//Output file
	ofstream out("data.txt");
	
	
	//total time of the simulation
	long Sim_time_tot(T_Stop/h);
	
	//for terminal
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
	
	//Simulation time
	for (long time = 0; time <= T_Stop; ++time)
	{
		//checks if there is current or not
		if ((time > Current_Start) and (time < Current_Stop))
		{
			//only the first gets current here
			if (neurons[0].update(time, EXT_CURRENT)) {
				//spike has occured, we pass the spike to the other
				neurons[1].plugin_spike();
			}
			
			//the second one doesnt get current in this simulation
			neurons[1].update(time, 0.0);
		
		//out of the times with current, no current is given	
		} else {
			neurons[0].update(time, 0.0);
			neurons[1].update(time, 0.0);
		}

		//printing in file
		out << 1 << "->" << neurons[0].get_V_mem() << "pA at t=" << time*h << "ms" << "\t" << "\t"
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

