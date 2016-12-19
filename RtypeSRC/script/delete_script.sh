#!/bin/bash

if [ "$#" -ne 1 ]
then
  echo "Usage: delete_script name_script"
  exit 1
fi

rm -rf source/"$1"
rm -rf include/"$1"
sed -i "s/include(\${SCRIPT_SOURCE_DIR}\/"$1"\/CMakeLists.txt)//g" CMakeLists.txt
#sed ':a;N;$!ba;s/\n/ /g' CMakeLists.txt