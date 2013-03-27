#!/bin/bash
#
# result - script to finish up the task
#

echo -n "[puzzlebox] "

if [ -x "${0}" ]; then
	echo -n "1 "
	if [ -L "${0}" ] && [ "${0#**/}" = "solution" ]; then
		echo -n "2 "
		if [ "`tail -1 ${0} | grep \"^#${USER}:.*$\" | wc -l`" -eq 1 ]; then
			echo -n "YES, here is your token: "
			md5sum "${0}" | cut -d' ' -f1
		else
			echo "Very close."
			exit 1
		fi
	else
		echo "Closer."
		exit 1
	fi
else
	echo "Not yet."
	exit 1
fi

exit 0
#username:Fill out the previous field as appropriate
