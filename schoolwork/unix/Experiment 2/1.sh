#!/bin/bash
#
#A script to create a script
#

fileNum=1
nextFileNum=`bc <<< $fileNum+1`

echo -e $fileNum
echo -e "This is a file to create a script"
echo -e "It will take this script file, and create a new script named one number higher"

echo 'echo -e "This is a file to create a script"
echo -e "It will take this script file, and create a new script named one number higher"' > $nextFileNum.sh

