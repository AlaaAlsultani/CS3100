#!/bin/bash


for Threshold in 1 2 5 10 20 30 40 50 60 70 80 90 100; do
	for i in [1..5]; do
		./hw7 1000000000 $Threshold
	done
done
