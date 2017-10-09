#ifndef Neuron_H
#define Neuron_H

#include <vector>
using namespace std;


class Neuron
{
	public :
		
		//Constructor
		Neuron (double membranePotential_ = 0.0,
				int numberSpike_ = 0);
		
		//Destructor
		~Neuron() {};
		
		//Update
		void update(double time, double current_);
		
		//Setters
		void setMembranePotential(double newPotential);
		void setNumberSpike(double newNumber);
		void setStimulusTime(int timeOfOccurence);
		void clearSpikeTime();
		
		
	private :
		
		//Potential of the membrane V
		double membranePotential;
		
		//Number of spikes occured
		int numberSpike;
		
		//time when a spike occured
		vector<unsigned int> spikeTime;
		
	
		
};



#endif
