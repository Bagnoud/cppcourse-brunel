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
const double J_Spike = 0.1; //mV spike sent

#endif
