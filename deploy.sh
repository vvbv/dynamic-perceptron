#!bin/bash
rm dynamic_perceptron
clear
g++ -g --std=c++11 src/*.cpp -I include/ -o dynamic_perceptron
./dynamic_perceptron
echo "dynamic_perceptron [ exit code:" $? "]"