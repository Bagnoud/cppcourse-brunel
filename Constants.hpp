#ifndef Constants_H
#define Constants_H



//Time
const int T_Stop = 5000;	//!< Time when simulation stops
const double h = 0.1;	//!< step time

//Declaration of the current [pA]
const double EXT_CURRENT(0.0);	//!< External current
	

// Constants
const double R = 20.0; //!< Resistance membrane
const double TAU = 20.0; //!< Membrane time constant
const double V_THR = 20.0; //!< Threshold
const double T_REFR = 2.0; //!< Refractory time
const double Delay = 1.5; //!< Delay of spike
const double Je_Spike = 0.1; //!< mV spike sent by excitatory
const double Ji_Spike = -0.5; //!< mV spike sent by inhibitory
const double Vext = 2.0;	//!< Spikes per ms
const double J_ext = 0.1;	//!< Weight of the background noise

//nu_ext = Vext* v_thr/(J_ext*TAU)

///1250 ok
const int Nb_neurons = 12500;	//!< Total number of neurons


enum Type_of_Neuron {EXCITATORY, INHIBITORY};	//!< Two types of neurons

#endif
