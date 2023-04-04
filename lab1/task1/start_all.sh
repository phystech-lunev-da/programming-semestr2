#!/bin/sh

echo compile binary_asimptotic_average.cpp
g++ binary_asimptotic_average.cpp -o binary_asimptotic_average
echo Done!
echo compile binary_asimptotic_bad.cpp
g++ binary_asimptotic_bad.cpp -o binary_asimptotic_bad
echo Done!
echo compile simple_asimptotic_average.cpp
g++ simple_asimptotic_average.cpp -o simple_asimptotic_average
echo Done!
echo compile simple_asimptotic_bad.cpp
g++ simple_asimptotic_bad.cpp -o simple_asimptotic_bad
echo Done!

./binary_asimptotic_average
./binary_asimptotic_bad
./simple_asimptotic_average
./simple_asimptotic_bad