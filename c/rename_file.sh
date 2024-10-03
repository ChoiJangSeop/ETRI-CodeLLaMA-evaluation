#!/bin/bash

# 모든 파일에 대해 처리
for file in *; do
    # 파일명에서 숫자 부분 추출 (숫자와 _ 사이의 문자열)
    number=$(echo "$file" | grep -o '^[0-9]\+')

    # 숫자가 있는 파일만 이름 변경
    if [ -n "$number" ]; then
        mv "$file" "${number}.c"
    fi
done

