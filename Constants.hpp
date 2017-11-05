#ifndef Constants_H
#define Constants_H


//Time
const int T_Stop = 2000;	//!< Time when simulation stops
const double h = 0.1;	//!< step time

//Declaration of the current [pA]
const double EXT_CURRENT(0.0);	//!< External current

//Number of neurons
const int Nb_neurons = 12500;	//!< Total number of neurons	


//Type of neurons
enum Type_of_Neuron {EXCITATORY, INHIBITORY};	//!< Two types of neurons

// Constants
const double R = 20.0; //!< Resistance membrane
const double TAU = 20.0; //!< Membrane time constant
const double V_THR = 20.0; //!< Threshold
const double T_REFR = 20; //!< Refractory time
const double Delay = 1.5; //!< Delay of spike
const double Je_Spike = 0.1; //!< mV spike sent by excitatory

const double Teta = 20; 
const double Vext = 2.0;	//!< Spikes per ms
const double J_ext = 0.1;	//!< Weight of the background noise
const double Eta = 2;


///Graph A
/*
const double Ji_Spike = -0.3; //!< mV spike sent by inhibitory
const double Lambda = 2.0;
*/

///Graph B
/*
const double Ji_Spike = -0.6; //!< mV spike sent by inhibitory
const double Lambda = 4.0;
*/

///Graph C
const double Ji_Spike = -0.5; //!< mV spike sent by inhibitory

//Poisson law
const double NuThr = (Teta/(0.1*0.8*Nb_neurons*Je_Spike*TAU));	//!< Constants used in the poisson law
const double NuExt = (Eta*0.1*0.8*Nb_neurons*NuThr);	//!< Constants used in the poisson law
const double Lambda = (NuExt * h);	//!< Constants used in the poisson law

///Graph D
/*
const double Ji_Spike = -0.45; //!< mV spike sent by inhibitory
const double Lambda = 0.9;
*/



#endif
