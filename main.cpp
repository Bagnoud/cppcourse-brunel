#include <iostream>
#include <fstream>
#include "neuron.hpp"
//#include "Constants.hpp"
using namespace std;

///Also in external file
int T_Stop(5000);
double h(0.1);	//step time
int Current_Start(1000);
int Current_Stop(4000);

//Declaration of the current [pA]
double EXT_CURRENT(1.001);


int main(int argc)	///by default =1
{
	ofstream out("data.txt"); //Output file
	
	Neuron neurone; //Construction of a neuron
	
	long Sim_time_tot(T_Stop/h);	//total time of the simulation
	
	///check for other current
	cout << "Current at : " << EXT_CURRENT << endl;
	
	//Simulation
	for (long time = 0; time <= T_Stop; ++time)
	{
		if ((time > Current_Start) and (time < Current_Stop))
		{
			neurone.update(time, EXT_CURRENT);
		} else {
			neurone.update(time, 0.0);
		}
		
		out << neurone.get_V_mem() << "pA at t=" << time << "ms" << endl;
	}


	return 0;
}

