#!/bin/bash

total_tests=0
passed_tests=0
failed_tests=0


run_test() {
	total_tests=$((total_tests + 1))
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
		passed_tests=$((passed_tests + 1))
	else
		echo "💀 Test failed."
		failed_tests=$((failed_tests + 1))
	fi
	echo "-------------------------"
}


###############
# 正常系
###############

# char A
run_test "a" \
"char: 'a'
int: 97
float: 97.0f
double: 97.0"

# char Z
run_test "Z" \
"char: 'Z'
int: 90
float: 90.0f
double: 90.0"

# char DEL
run_test $'\x7F' \
"char: Non displayable
int: 127
float: 127.0f
double: 127.0"

# int 42
run_test "42" \
"char: '*'
int: 42
float: 42.0f
double: 42.0"

# int -42
run_test "-42" \
"char: Non displayable
int: -42
float: -42.0f
double: -42.0"

# int 0
run_test "0" \
"char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# float 42.0
run_test "42.0f" \
"char: '*'
int: 42
float: 42.0f
double: 42.0"

# float -42.0
run_test "-42.0f" \
"char: Non displayable
int: -42
float: -42.0f
double: -42.0"

# float 0.0
run_test "0.0f" \
"char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# float +inff
run_test "+inff" \
"char: impossible
int: impossible
float: inff
double: inf"

# float -inff
run_test "-inff" \
"char: impossible
int: impossible
float: -inff
double: -inf"

# float nanf
run_test "nanf" \
"char: impossible
int: impossible
float: nanf
double: nan"

# double 42.0
run_test "42.0" \
"char: '*'
int: 42
float: 42.0f
double: 42.0"

# double -42.0
run_test "-42.0" \
"char: Non displayable
int: -42
float: -42.0f
double: -42.0"

# double 0.0
run_test "0.0" \
"char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# double +inf
run_test "+inf" \
"char: impossible
int: impossible
float: inff
double: inf"

# double -inf
run_test "-inf" \
"char: impossible
int: impossible
float: -inff
double: -inf"

# double nan
run_test "nan" \
"char: impossible
int: impossible
float: nanf
double: nan"

###############
# 異常系
###############

run_test "4ff" \
"char: impossible
int: impossible
float: impossible
double: impossible"

run_test "abc" \
"char: impossible
int: impossible
float: impossible
double: impossible"

run_test "+++" \
"char: impossible
int: impossible
float: impossible
double: impossible"

run_test "   " \
"char: impossible
int: impossible
float: impossible
double: impossible"

echo "========================="
echo "       Test Summary      "
echo "========================="
echo "Total tests: $total_tests"
echo "Tests passed: $passed_tests"
echo "Tests failed: $failed_tests"
