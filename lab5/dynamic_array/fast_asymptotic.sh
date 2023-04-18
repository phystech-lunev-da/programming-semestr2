#!/bin/bash

for type in linear double 
do

file="${type}_asymptotic.csv"

echo "size time" > $file

done

for ((i = 10; i <= 100000; i+=100))
do

for type in linear double 
do

file="${type}_asymptotic.csv"
./dynamic_array_time $type $i >> $file

done

done
