#!/bin/bash

PRG="./PmergeMe"
red='\033[0;31m'
green='\033[0;32m'
blue='\033[0;34m'
default='\033[0m'

# Initialize counters
total_tests=0
passed_tests=0

# function
function run_test()
{
	local n="$1"

	random_array=$(jot -r $n 1 100000 | tr '\n' ' ')
	echo "----------------------------------"
	"$PRG" $random_array

	if [ $? -eq 0 ]; then
		echo -e "✅ ${green}Test passed! ${default}"
		passed_tests=$((passed_tests+1))
	else
		echo -e "❌ ${red}Test passed! ${default}"
	fi
	total_tests=$((total_tests+1))
}

run_test 1
run_test 3
run_test 10
run_test 50
run_test 100
run_test 1000
run_test 3000

if [ $total_tests -eq $passed_tests ]; then
	echo -e "\n---- 🍺 ${green}All tests passed ${default} ----"
else
	echo -e "\n---- 🍺 ${red}tests failed ${default} ----"
fi
exit 0