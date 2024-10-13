#!/bin/bash

# 色設定
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # リセット

# 集計用の変数
AC_count=0
WA_count=0

# テストケースファイルの読み込みと実行関数
run_testcases() {
  local testcase_file="$1"
  local test_type="$2"
  local i=1

  if [ ! -f "$testcase_file" ]; then
    echo "$testcase_file file not found!"
    return
  fi

  echo "Running tests from $testcase_file ($test_type):"

  while IFS=";" read -r argv expected_answer
  do
    # ./push_swapを実行し、結果を取得
    result=$(../push_swap $argv)
    
    # テストケースの番号表示
    echo "--- $test_type testcase $i ---"
    
    # input, output, expectedの表示
    echo "input    : $argv"
    echo "output   : $result"
    echo "expected : $expected_answer"
    
    # 実行結果と期待結果を比較し、AC か WA の色付き結果を表示
    if [ "$result" == "$expected_answer" ]; then
      echo -e "Result   : ${GREEN}AC${NC}"
      AC_count=$((AC_count + 1))
    else
      echo -e "Result   : ${RED}WA${NC}"
      WA_count=$((WA_count + 1))
    fi

    # 次のテストケースの間に空行を追加
    echo ""
    i=$((i + 1))
  done < "$testcase_file"
}

# 正常なテストケースとエラーテストケースを実行
run_testcases "testcases.txt" "Normal"
run_testcases "errortestcases.txt" "Error"

# 最後にACとWAの集計結果を表示
echo "$AC_count AC, $WA_count WA"