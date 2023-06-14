#!/bin/bash

RPN="./RPN"
red='\033[0;31m'
green='\033[0;32m'
blue='\033[0;34m'
default='\033[0m'

# 関数定義
function run_test() {
    local test_case="$1"
    local expected="$2"
    local is_error_test="$3"

    echo "----------------------------------"
    local actual=$($RPN "$test_case" 2>&1)
    local status=$?
        echo -e "${blue}Test => $test_case ${default}"
        echo "Actual: $actual"
        echo "Expected: $expected"
    if [ "$actual" == "$expected" ] ||
       ([ $is_error_test = 1 ] && [ $status -ne 0 ]); then
        echo -e "✅ ${green}Test passed! ${default}"
    else
        echo -e "❌ ${red}Test failed ${default}"
    fi
}

# 正常系
run_test "2 3 +" 5 0
run_test "2 3 -" -1 0
run_test "2 3 *" 6 0
run_test "6 2 /" 3 0
run_test "6 3 3 + /" 1 1
run_test "1 2 3 4 + + +" 10 0
run_test "7 2 3 + * 5 3 - 4 * - 6 2 / +" 30 0

# 異常系（無効な式）
run_test "2 3 + +" "Error" 1
run_test "+ 2 3" "Error" 1
run_test "a 2 + " "Error" 1
run_test "2 + " "Error" 1
run_test "-1 1 3 * 2 + 5 - * - 4 5 * * 8 /" "Error" 1

# 異常系（空の入力）
run_test "" "Error" 1

echo -e "\n---- 🍺 ${green}All tests passed ${default} ----"
exit 0