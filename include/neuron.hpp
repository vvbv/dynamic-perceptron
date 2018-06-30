#ifndef NEURON_HPP_
#define NEURON_HPP_

    #include <cmath>
    #include <vector>
    #include <string>
    #include <fstream>
    #include <cstring>

    using std::abs;
    using std::vector;
    using std::string;
    using std::ifstream;
    using std::ofstream;
    using std::to_string;
    using std::getline;
    using std::strtok;

    class Neuron{

        private:

            const string NEURON_CODENAME = "{NEURON_CODENAME}";
            const string NEURAL_NETWORK_STRUCTURE_FILE = "{NEURAL_NETWORK_STRUCTURE_FILE}";

            long double weight;
            vector < long double > input;
            int layer_number;

            long double fast_sigmoid( long double value );
            long double evaluate_input( vector < long double > input );
            void write_output( long double output_value );

            vector<string> string_tok( string line, char spliter );

        public:
            Neuron();
            ~Neuron();
            void load_local_information();

    };

#endif