#!bin/bash

mkdir deploy_area
cd deploy_area
mkdir swap_area

rm -R include
rm -R src
rm -R examples
rm -R swap_area/*.ndp

cp -r ../include ../deploy_area
cp -r ../src ../deploy_area
cp -r ../examples ../deploy_area

NEURON_CODENAME='NC0'
NEURAL_NETWORK_STRUCTURE_FILE='example_1_structure.conf'
WEIGHT='0.9'
LAYER_NUMBER='0'

sed -i -e 's/{NEURON_CODENAME}/'$NEURON_CODENAME'/g' include/neuron.hpp
sed -i -e 's/{NEURAL_NETWORK_STRUCTURE_FILE}/'$NEURAL_NETWORK_STRUCTURE_FILE'/g' include/neuron.hpp
sed -i -e 's/this->weight = 0.5;/this->weight = '$WEIGHT';/g' src/neuron.cpp
sed -i -e 's/this->layer_number = 0;/this->layer_number = '$LAYER_NUMBER';/g' src/neuron.cpp

rm dynamic_perceptron
clear

g++ -g --std=c++11 src/*.cpp -I include/ -o dynamic_perceptron
./dynamic_perceptron

echo "dynamic_perceptron [ exit code:" $? "]"