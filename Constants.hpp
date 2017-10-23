#ifndef Constants_H
#define Constants_H



//Time
const int T_Stop = 5000;
const int Current_Start = 1000;
const int Current_Stop = 4000;
const double h = 0.1;	//step time

//Declaration of the current [pA]
const double EXT_CURRENT(1.01);
	

// Constants
const double R = 20.0; // Resistance membrane
const double TAU = 20.0; // Membrane time constant
const double V_THR = 20.0; // Threshold
const double T_REFR = 2.0; // Refractory time
const double Delay = 1.5; //Delay of spike
const double Je_Spike = 0.1; //mV spike sent by excitatory
const double Ji_Spike = -0.5; //mV spike sent by inhibitory
const double Vext = 0.02;	//Spikes per ms

///x10 
const int Nb_excitatory = 1000;
const int Nb_inhibitory = 250;

enum Type_of_Neuron {EXCITATORY, INHIBITORY};

#endif
