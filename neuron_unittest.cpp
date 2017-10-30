#include "neuron.hpp"
#include "gtest/gtest.h"
#include <iostream>



TEST (NeuronTest, PositiveImput)
{
	double current(1.0);
	
	Neuron neuron_test;
	neuron_test.update_TEST(1, current);
	
	EXPECT_EQ(exp(-h/TAU)*0+ current*R*(1-exp(-h/TAU)), neuron_test.get_V_mem());
}


TEST (NeuronTest, NegativeImput)
{
	double current(-1.0);
	
	Neuron neuron_test;
	neuron_test.update_TEST(1, current);
	
	EXPECT_EQ(0, neuron_test.get_V_mem());
}


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



/*
TEST (NetworkTest, NAME)
{
	
	
}
*/







int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
