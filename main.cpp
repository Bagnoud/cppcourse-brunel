#include <iostream>
using namespace std;



//time start and stop
constexpr int TIME_START(0);
constexpr int TIME_STOP(100);

//Declaration of the current [pA]
constexpr double EXTERNAL_CURRENT(1);




int main()
{
	//Declaration of time interval
	int time(timeStart);
	
	//Declaration of the time when n update
	int n(10);
	
	//Construction of a neuron
	Neuron neurone;
	

	//Simulation
	for (time; time <= timeStop; ++time)
	{
		//if update can be called
		if (time % n == 0) {
			neurone.update(time, EXTERNAL_CURRENT);
		}	
	}
	
	

	return 0;
}
