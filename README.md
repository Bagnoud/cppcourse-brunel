# CS116-2017-Alexandre-Bagnoud

My project uses the following files :

CMakeLists.txt
Constants.hpp
Network.cpp
Network.hpp
main.cpp
neuron.cpp
neuron.hpp
neuron_unittest.cpp

A pdf with the four different graphs is included in the repository.

The current version reproduces the graph C of figure 8, described in Brunel, N J. Comp Neuroscience 2000.
To reproduce the other graphs, uncomment a section in Constants.hpp.

Constants such as time of the simulation can be changed in the file Constants.hpp

./Neuron to run the simulation      
./neuron_unittest to run the tests

Data will be printed on the file "data.txt"

All other files were created for either Google test or doxygen documentation.
