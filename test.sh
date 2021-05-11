#!/bin/sh

executabledir="./output/"
executable="numconv"

#############################################################################################################
# ATTENTION WHEN CHECKING FOR STRING CONVERSION A EXTRA SPACE IS REQUIRED AT THE END OF THE EXPECTED OUTPUT #
#############################################################################################################

parameters=(
	"-i 16 -n 0 -o 2"
	"-i 16 -n f16 -o 2"
	"-i 16 -n f16 -o 10"
	"-i 2 -n 1010 -o 2"
	"-i 2 -n 1010 -o 10"
	"-i 2 -n 1010 -o 16"
	"-i 10 -n 432 -o 2"
	"-i 10 -n 421 -o 32"
	"-i 10 -n 55 -o 10"
	"-i 5 -n 423 -o 13"
	"-s Hello -o 2"
	"-s HelloMyFriend -o 10"
)

expectations=(
	"0"
	"111100010110"
	"3862"
	"1010"
	"10"
	"A"
	"110110000"
	"D5"
	"55"
	"89"
	"1001000 1100101 1101100 1101100 1101111 "
	"72 101 108 108 111 77 121 70 114 105 101 110 100 "
)

length=${#parameters[@]}
success=0
failed=0

for (( i = 0; i < $length; i++ ))
do
	output="$($executabledir$executable ${parameters[$i]})"
	if [ "$output" = "${expectations[$i]}" ] 
	then 
		echo -e "OK\t$executabledir$executable ${parameters[$i]}"
		(( success++ )) 
	else
		echo -e "FAILED\t$executabledir$executable ${parameters[$i]} expected ${expectations[$i]} but got $output"
		(( failed++ ))
	fi
done

echo -e "\n$success SUCCESSFUL $failed FAILED"
