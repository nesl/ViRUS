#/bin/bash


infs=(16K 16 4K 4 64K)

rm times/*
for repetitions in `seq 0 1`
do
	for qLevel in 0 1 2 3
	do
		for inf in ${infs[@]}
		do
			  {  /usr/bin/time -f "%e" src/blackscholes 1 inputs/in_${inf}.txt run/prices_${inf}_${qLevel}.txt $qLevel; } 2>> times/time_${inf}_${qLevel}.txt
		done
	done
done
