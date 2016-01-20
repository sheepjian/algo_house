#!/bin/bash

if [[ $# -ne 2 ]] ; then
    echo "Usage: question create/delete string"; exit 1
fi

TestSuffix='_test.cpp'
TestFile="$2${TestSuffix}"
FILE_UPPER=$( echo $2 | tr '[:lower:]' '[:upper:]' )

if [[ $1 = "delete" ]]; then
  #statements
  rm -rf src/$2
  rm test/$TestFile
elif [[ $1 = "create" ]]; then
  if [[ ! -d "$2" ]]; then
      mkdir src/$2
      dt=$(date '+%Y-%m-%d %H:%M:%S');
      sed -e "s/\[FILE_NAME\]/$2/g" -e "s/\[CREATE_TIME\]/$dt/g" Common/header.txt > src/$2/$2.h
      sed -e "s/\[FILE_NAME_UPPER\]/${FILE_UPPER}/g" -e "s/\[FILE_NAME\]/$2/g" -e "s/\[CREATE_TIME\]/$dt/g" Common/unittest.txt > test/$TestFile
      cp Common/readme.txt src/$2/README.md
  else
    echo "the question already exist"
  fi
else
  echo "Invalid command! Usage: question create/delete string"; exit 1
fi