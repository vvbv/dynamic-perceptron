#include "neuron.hpp"

Neuron::Neuron(){
    this->weight = 0.5;
    this->layer_number = 0;
};

Neuron::~Neuron(){};

long double Neuron::fast_sigmoid( long double value ){
    return value / ( 1 + abs( value ) );
};

void Neuron::load_local_information(){

    vector < long double > input;
    input.push_back( 1 );
    input.push_back( 3 );

    write_output( this->evaluate_input( input ) );

};

long double Neuron::evaluate_input( vector < long double > input ){

    int input_size = input.size();
    long double input_value = 0;

    for( int i = 0; i < input_size; i++ ){
        input_value += input[i];
    };

    return input_value * this->weight;

};

void Neuron::write_output( long double output_value ){
    string output_file_location = "swap_area/" + this->NEURON_CODENAME + ".ndp";
    ofstream outpur_file;
    outpur_file.open ( output_file_location );
    outpur_file << "#OUTPUT VALUE\n";
    outpur_file << to_string( output_value );
    outpur_file.close();
};