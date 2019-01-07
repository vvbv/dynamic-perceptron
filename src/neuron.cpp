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

    struct structure_info{
        string origin_neuron;
        string destiny_neuron;
    };

    vector<structure_info>neuron_map;

    ifstream input_file( this->NEURAL_NETWORK_STRUCTURE_FILE );
    string line = "";
    while( getline( input_file, line ) ){
        if( line.size() > 0 ){
            if( line[0] =! '#' ){
                vector<string>tok = this->string_tok( line, '>' );
                structure_info declaration;
                declaration.origin_neuron = tok[0];
                declaration.destiny_neuron = tok[1];
                if( declaration.destiny_neuron == this->NEURON_CODENAME ){
                    neuron_map.push_back( declaration );
                }; 
            };
        };
    };

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
    string output_file_location = "swap_area/OUTPUT_" + this->NEURON_CODENAME + ".ndp";
    ofstream outpur_file;
    outpur_file.open ( output_file_location );
    outpur_file << "#OUTPUT VALUE\n";
    outpur_file << to_string( output_value );
    outpur_file.close();
};

vector<string> Neuron::string_tok( string line, char spliter ){
    vector<string>to_return;
    int line_size = line.size();
    string tmp_line = "";
    for( int i = 0 ; i < line_size; i++ ){
        if( line[i] == spliter ){
            to_return.push_back( tmp_line );
        }else{
            tmp_line += line[i];
        };
    };
    to_return.push_back( tmp_line );
    return to_return;
};

void Neuron::print(){
    cout << "CODENAME: " << this->NEURON_CODENAME << endl;
    cout << "WEIGHT: " << this->weight << endl; 
    cout << "LAYER NUMBER: " << this->layer_number << endl;
};