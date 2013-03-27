#!/bin/bash
#
echo -n "Enter a number: "
read number
echo -n "How many times: "
read times
for ((i = $number; i < $times; i++));do
let x=i*i
echo "[$i] $x"
done
