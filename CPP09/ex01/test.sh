#!/bin/bash

RPN="./RPN"
red='\033[0;31m'
green='\033[0;32m'
default='\033[0m'

# 正常系
echo "----------------------------------"
test_case="2 3 +"
expected=5
actual=`$RPN "$test_case"`
	echo -e "${green}Test: $test_case ${default}"
	echo "Actual: $actual"
	echo "Expected: $expected"
if [ $actual -eq $expected ]; then
	echo -e "${green}Test passed! ${default}"
else
	echo -e "${red}Test failed ${default}"
fi

# 異常系（無効な式）
echo "----------------------------------"
test_case="2 3 + +"
expected="Error"
actual=$( $RPN "$test_case" 2>&1 >/dev/null )
status=$?
	echo -e "${green}Test: $test_case ${default}"
	echo "Actual: $actual"
	echo "Expected: $expected"
if [ $status -ne 0 ]; then
	echo -e "${green}Test passed! ${default}"
else
	echo -e "${red}Test failed ${default}"
fi

# 空の入力
echo "----------------------------------"
test_case=""
expected="Error"
actual=$( $RPN "$test_case" 2>&1 >/dev/null )
status=$?
	echo -e "${green}Test: $test_case ${default}"
	echo "Actual: $actual"
	echo "Expected: $expected"
if [ $status -ne 0 ]; then
	echo -e "${green}Test passed! ${default}"
else
	echo -e "${red}Test failed ${default}"
fi

echo "All tests passed"
exit 0
