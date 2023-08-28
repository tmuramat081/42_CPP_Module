#!/bin/bash

run_test() {
	input="$1"
	expected="$2"

	output=$(./convert "$input")
	echo "-------------------------"
	echo "Test case for \"$input\""
	echo "## Expected"
	echo "$expected"
	echo "## Got"
	echo "$output"
	if [ "$output" == "$expected" ]; then
		echo "✅ Test passed!"
	else
		echo "💀 Test failed."
	fi
	echo "-------------------------"
}


###############
# 正常系
###############

# A
run_test "a" \
"char: a
int: 97
float: 97.0f
double: 97.0"

# Z
run_test "Z" \
"char: "Z"
int: 90
float: 90.0f
double: 90.0"

# NULL
run_test "0" \
"char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# DEL
run_test $'\x7F' \
"char: Non displayable
int: 127
float: 127.0f
double: 127.0"

# INT_MIN
run_test "-2147483648" \
"char: impossible
int: -2147483648
float: -2147483648.0f
double: -2147483648.0"

# INT_MAX
run_test "2147483647" \
"char: impossible
int: 2147483647
float: 2147483647.0f
double: 2147483647.0"

# テストケース2
run_test "nan" \
"char: impossible
int: impossible
float: nanf
double: nan"

###############
# 異常系
###############