#!bin/bash
rm dynamic_percepton
g++ -g --std=c++11 src/*.cpp -I include/ -o dynamic_percepton
./dynamic_percepton
