#include "neuron.hpp"
#include "Network.hpp"
#include "gtest/gtest.h"
#include <iostream>


/**
 * Tests if the potential of one neuron is correctly computed
 * after one update with positive imput
 */
TEST (NeuronTest, PositiveImput)
{
	double current(1.0);
	
	Neuron neuron_test;
	neuron_test.update_TEST(1, current);
	
	EXPECT_EQ(exp(-h/TAU)*0+ current*R*(1-exp(-h/TAU)), neuron_test.get_V_mem());
}




/**
 * The membrane should then to 20, but never spike
 */
TEST (NeuronTest, NoSpike)
{
	double current(1.0);
	
	Neuron neuron_test;
	
	for(int time(0); time < 5000; ++time)
	{
		neuron_test.update_TEST(time, current);
	}
	
	//should not have spiked
	EXPECT_EQ(0, neuron_test.get_nb_spikes());
	
	//the membrane should be close to 20
	EXPECT_GT(1E-3, std::fabs(19.999-neuron_test.get_V_mem()));
}



/**
 * Standalone simulation, we expect 4 spikes in a period of 400ms
 * with a current of 1.01
 */
TEST (NeuronTest, SimulationOneNeuron)
{
	double current(1.01);
	
	Neuron neuron_test;
	
	for(int time(0); time < 4000; ++time)
	{
		neuron_test.update_TEST(time, current);
	}
	
	//should have spiked 4 times
	EXPECT_EQ(4, neuron_test.get_nb_spikes());
}




/**
 * Tests if the spikes occurs at the right time
 * testing on the first three spikes
 */
TEST (NeuronTest, SpikeTime)
{
	double current(1.01);
	
	Neuron neuron_test;
	
	for(int time(0); time < 923; ++time) {
		neuron_test.update_TEST(1, current);
	}
	
	EXPECT_EQ(0, neuron_test.get_nb_spikes());
	neuron_test.update_TEST(924, current);
	EXPECT_EQ(1, neuron_test.get_nb_spikes());
	
	
	//second spike
	for(int time(925); time < 1868; ++time) {
		neuron_test.update_TEST(1, current);
	}
	
	EXPECT_EQ(1, neuron_test.get_nb_spikes());
	neuron_test.update_TEST(1869, current);
	EXPECT_EQ(2, neuron_test.get_nb_spikes());
	
	//third spike
	for(int time(1870); time < 2813; ++time) {
		neuron_test.update_TEST(1, current);
	}
	
	EXPECT_EQ(2, neuron_test.get_nb_spikes());
	neuron_test.update_TEST(2814, current);
	EXPECT_EQ(3, neuron_test.get_nb_spikes());
}




/**
 * Tests the delay buffer after one spike, and the transmission
 * from one neuron to the other
 */
TEST (NeuronTest, TransmissionOfSpike)
{
	double current(1.01);
	double delay(15);	//delay is 15 steps or 1.5ms
	
	Neuron neuron_test_1;
	Neuron neuron_test_2;
	
	for(int time(0); time < 924+delay; ++time)
	{
		if(neuron_test_1.update_TEST(time, current))
		{
			neuron_test_2.plugin_spike(0.1);
		}
		
		neuron_test_2.update_TEST(time, 0.0);
	}
	
	
	//the potential of the 2nd neuron should be equal to the imput
	EXPECT_EQ(0.1, neuron_test_2.get_V_mem());
}




/**
 * Tests if one neuron has 10% of connections leading to him
 */
TEST (NetworkTest, RightNumberOfConnections)
{
	Network network_test;
	network_test.Creating_Connections();
	
	//testing for neuron 4
	EXPECT_EQ(0.1*Nb_neurons, network_test.Count_number_connections(3));
	
	//testing for neuron 6001
	EXPECT_EQ(0.1*Nb_neurons, network_test.Count_number_connections(6000));
	
	//testing for neuron 112001
	EXPECT_EQ(0.1*Nb_neurons, network_test.Count_number_connections(11200));
}





int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
