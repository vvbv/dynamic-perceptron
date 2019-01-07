#include "main.hpp"
#include "neuron.hpp"

int main( int argc, const char* argv[] ){

    Neuron neuron;
    neuron.load_local_information();

    if( argc != 0  ){
        if( string( argv[1] ) == "-i" ){
            neuron.print();
        }
    }
    
    return 0;
};