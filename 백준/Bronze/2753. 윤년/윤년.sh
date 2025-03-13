#!/bin/bash

read year
#윤년계산(이중 괄호로 비교 연산)
if (( $year % 4 == 0 && $year % 100 != 0 )) || (( $year % 400 == 0 )); then
  echo 1
else
  echo 0
fi