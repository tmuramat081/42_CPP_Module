#!/bin/bash

RPN="./RPN"
red='\033[0;31m'
green='\033[0;32m'
default='\033[0m'

# 正常系
test_case="2 3 +"
	echo -e "${green}Test: $test_case ${default}"
expected=5
actual=`$RPN "$test_case"`
	echo "Actual: $actual"
	echo "Expected: $expected"
if [ $actual -eq $expected ]; then
	echo -e "${green}Test passed! ${default}"
else
	echo -e "${red}Test failed ${default}"
	exit 1
fi

# 異常系（無効な式）
test_case="2 3 + +"
	echo -e "${green}Test: $test_case ${default}"
expected="Error"
actual=`$RPN "$test_case"` 2>&1 >/dev/null
	echo "Actual: $actual"
	echo "Expected: $expected"
if [ $? -ne 0 ]; then
	echo "Test passed"
else
	echo "Test failed"
	exit 1
fi

# 空の入力
test_case=""
expected="Error"
actual=`$RPN "$test_case"` 2>&1 >/dev/null
if [ $? -ne 0 ]; then
	echo "Test passed: $test_case = $expected"
else
	echo "Test failed: $test_case, expected $expected, got no error"
	exit 1
fi

echo "All tests passed"
exit 0