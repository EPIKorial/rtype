#!/bin/bash
MINPARAMS=2

if [ "$#" -ne 1 ]
then
  echo "Usage: ./script script_name"
  exit 1
fi

SCRIPT_UP_NAME=$(echo $1 | tr 'a-z' 'A-Z')

mkdir source/"$1"
mkdir include/"$1"
cp source/Default/* source/"$1"
cp include/Default/* include/"$1"
mv source/"$1"/Default.cpp source/"$1"/"$1".cpp
mv include/"$1"/Default.hpp include/"$1"/"$1".hpp

sed -i "s/Default/"$1"/g" source/"$1"/"$1".cpp include/"$1"/"$1".hpp source/"$1"/CMakeLists.txt
sed -i "s/DEFAULT/"$SCRIPT_UP_NAME"/g" source/"$1"/"$1".cpp include/"$1"/"$1".hpp source/"$1"/CMakeLists.txt

echo "include(\${SCRIPT_SOURCE_DIR}/$1/CMakeLists.txt)" >> CMakeLists.txt