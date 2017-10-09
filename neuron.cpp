#include <iostream>
#include "neuron.hpp"
using namespace std;


//Constructeur

Neuron::Neuron (double membranePotential_ = 0.0, double numberSpike_ = 0.0)
: membranePotential(membranePotential_), numberSpike(numberSpike_),
stimulusTime()
{}


//Update

void Neuron::update(double time, double current_)
{
	//update of the neuron..?
	
	///update avec la mega formule, checker tes photos pour les constantes
	///pushback dans un tableau le potentiel membrenane a chaque update
	///
	
	
	
	
}



//Setters

void Neuron::setMembranePotential(double newPotential)
{
	membranePotential = newPotential;
}

void Neuron::setNumberSpike(double newNumber)
{
	numberSpike = newNumber;
}

void Neuron::setStimulusTime(int timeOfOccurence)	///////////
{
	stimulusTime.push_back(timeOfOccurence);
}

void Neuron::clearStimulusTime()
{
	stimulusTime.clear();
}





