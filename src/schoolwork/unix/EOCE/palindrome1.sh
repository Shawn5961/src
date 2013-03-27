#1/bin/bash
#
#Script 1 to check for palindromity
#
echo -n "Enter a word to be checked for palindromity: "
read word
wordReversed=`echo "$word" | rev`
if [ "$word" = "$wordReversed" ]; then
	echo "Yes, that is a palindrome!"
	exit 0
else
	echo "Not a palindrome! Get out of my house!"
fi
exit 0
