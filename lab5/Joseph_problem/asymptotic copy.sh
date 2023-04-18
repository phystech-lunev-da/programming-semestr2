#!/bin/bash

for type in buffer
do

file="${type}_asymptotic.csv"

echo "size time" > $file

done

for ((i = 10; i <= 10000; i+=100))
do

for type in buffer 
do

file="${type}_asymptotic.csv"
./Joseph_time $type $i >> $file

done

done
