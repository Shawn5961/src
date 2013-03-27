#!/bin/bash
#
#Script 2 to check for palindromacity
#
echo -n "Enter a word to be checked for palindromacity: "
read word
copy=${word}
len=${#copy}
echo $word
echo $copy
echo $len
for((i=$len;i>=0;i--)); do
	revword="$revword${copy:$i:1}"
done
echo $revword
echo $word
if [ "$word" = "$revword" ]; then
	echo "Congratulations, that is indeed a palindrome!"
	exit 0
else
	echo "That's no palindrome, sonny! Get off my lawn!"
fi
exit 0
