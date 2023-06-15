#!/bin/bash

PRG="./PmergeMe"
red='\033[0;31m'
green='\033[0;32m'
blue='\033[0;34m'
default='\033[0m'

# 関数定義
function run_test() {
    local test_case="$1"

    echo "----------------------------------"
	echo -e "Test Case: ${blue}$test_case${default}"
    "$PRG" "$test_case"
    echo -e "✅ ${green}Test passed! ${default}"
}

# 正常系
run_test "8 6 5 7 3 4 9 1 10 2"

echo -e "\n---- 🍺 ${green}All tests passed ${default} ----"
exit 0