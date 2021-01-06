#!/bin/sh

executabledir="./output/"
executable="main"

#ATTENTION WHEN CHECKING FOR STRING CONVERSION A EXTRA SPACE IS REQUIRED AT THE END OF THE EXPECTED OUTPUT SEE LINE 55 AND 60

parameters="-i 16 -n 0 -o 2"
expected="0"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-i 16 -n f16 -o 2"
expected="111100010110"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

#
parameters="-i 16 -n f16 -o 10"
expected="3862"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-i 2 -n 1010 -o 2"
expected="1010"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-i 2 -n 1010 -o 10"
expected="10"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-i 2 -n 1010 -o 16"
expected="A"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-i 10 -n 432 -o 2"
expected="110110000"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-i 10 -n 421 -o 32"
expected="D5"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-i 10 -n 55 -o 10"
expected="55"
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-s Hello -o 2"
expected="1001000 1100101 1101100 1101100 1101111 "
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"

parameters="-s HelloMyFriend -o 10"
expected="72 101 108 108 111 77 121 70 114 105 101 110 100 "
output="$($executabledir$executable $parameters)"
[ "$output" = "$expected" ] && printf "OK\t$executabledir$executable $parameters\n" || printf "$executabledir$executable $parameters expected $expected but got $output\n"
