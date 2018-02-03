#!/bin/bash
echo "1_m.txt"
COUNTER=0
count=0
while [ $count -lt 10 ]
	do
		./lem-in < maps/algo_2.txt
		(( count++ ))
	done

