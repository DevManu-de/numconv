#!/bin/sh

output="$(./output/main -i 16 -n 0 -o 2)"
if [ "$output" = "0" ]; then
	printf "./output/main -i 16 -n 0 -o 2\tOK\n"
else
	echo "./output/main -i 16 -n 0 -o 2 expected 0 but got $output"
fi;

output="$(./output/main -i 16 -n f17 -o 2)"
if [ "$output" = "111100010110" ]; then
	echo "OK"
else
	echo "./output/main -i 16 -n f16 -o 2 expected 111100010110 but got $output"
fi;

output="$(./output/main -i 16 -n f17 -o 10)" # && echo "Expected: 3862"

[ "$output" = "3862" ] && printf "./output/main -i 16 -n f16 -o 10\t OK\n" || printf "./output/main -i 16 -n f16 -o 10 expected 3862 but got $output\n"

##output=./output/main -i 2 -n 1010 -o 2 # && echo "Expected: 1010"
##output=./output/main -i 2 -n 1010 -o 10 # && echo "Expected: 10"
##output=./output/main -i 2 -n 1010 -o 16 # && echo "Expected: A"
##output=./output/main -i 10 -n 432 -o 2 # && echo "Expected: 110110000"
##output=./output/main -i 10 -n 421 -o 32 # && echo "Expected: D5"
##output=./output/main -i 10 -n 55 -o 10 # && echo "Expected: 55"
##output=./output/main -s Hello -o 2 # && echo "Expected: 1001000 1100101 1101100 1101100 1101111"
##output=./output/main -s HelloMyFriend -o 10 # && echo "Expected: 72 101 108 108 111 77 121 70 114 105 101 110 100"
