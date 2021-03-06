#!/bin/bash

mkdir deploy_area
cd deploy_area
rm -R ../deploy_area/*
mkdir build
mkdir build/swap_area

clear

cp -r ../include ../deploy_area
cp -r ../src ../deploy_area
cp -r ../$1/neurons.conf ../deploy_area/neurons.conf
cp -r ../$1/structure.conf ../deploy_area/structure.conf
cp -r ../$1/input.txt ../deploy_area/input.txt

cp include/neuron.hpp include/base_neuron.hpp
cp src/neuron.cpp src/base_neuron.cpp

NEURAL_NETWORK_STRUCTURE_FILE='structure.conf'
filename="neurons.conf"

while read -r line
do
    if [[ ${#line} > 0 ]]
    then
        if [[ ${line:0:1} != "#" ]]
        then
            declare -i counter=0
            NEURON_CODENAME=''
            WEIGHT=''
            LAYER_NUMBER=''
            for tok in $line; do 
                if [[ counter -eq 0 ]]
                then
                    NEURON_CODENAME=$tok
                    counter=$counter+1
                elif [[ counter -eq 1 ]]
                then
                    LAYER_NUMBER=$tok
                    counter=$counter+1
                elif [[ counter -eq 2 ]]
                then
                    WEIGHT=$tok
                fi
            done

            rm include/neuron.hpp
            rm src/neuron.cpp

            cp include/base_neuron.hpp include/neuron.hpp
            cp src/base_neuron.cpp src/neuron.cpp
            
            sed -i -e 's/{NEURON_CODENAME}/'$NEURON_CODENAME'/g' include/neuron.hpp
            sed -i -e 's/{NEURAL_NETWORK_STRUCTURE_FILE}/'$NEURAL_NETWORK_STRUCTURE_FILE'/g' include/neuron.hpp
            sed -i -e 's/this->weight = 0.5;/this->weight = '$WEIGHT';/g' src/neuron.cpp
            sed -i -e 's/this->layer_number = 0;/this->layer_number = '$LAYER_NUMBER';/g' src/neuron.cpp
            g++ -g --std=c++11 src/main.cpp src/neuron.cpp -I include/ -o build/$NEURON_CODENAME
            echo "[ Build completed ]:    Neuron:"$NEURON_CODENAME "[Weight:"$WEIGHT", Layer:"$LAYER_NUMBER"]"

        fi
    fi

done < "$filename"
rm include/base_neuron.hpp
rm src/base_neuron.cpp