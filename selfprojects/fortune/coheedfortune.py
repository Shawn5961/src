#!/usr/bin/env python
import urllib2
from BeautifulSoup import BeautifulSoup, SoupStrainer
import re
import random

page1 = urllib2.urlopen("http://www.azlyrics.com/c/coheedandcambria.html")
numLinks = 0
linkArray = []

for link in BeautifulSoup(page1, parseOnlyThese=SoupStrainer('a')):
	if link.has_key('href'):
		if link['href'].startswith(".."):
			numLinks += 1
			linkTemp = link['href']
			linkTemp = linkTemp.replace("..", "http://www.azlyrics.com")
			linkArray.append(linkTemp)

linkChoice = random.randint(0, numLinks-1)
#print linkArray[linkChoice]

page2 = urllib2.urlopen(linkArray[linkChoice])
soup2 = BeautifulSoup(page2)
numLines = 0
lineArray = []

for line2 in soup2.findAll(text=re.compile('\r\n')):
	if not "<" in line2:
		if not "cf_" in line2:
			if not "ArtistName" in line2:
				if not "SongName" in line2:
					if not "artist/album/song" in line2:
						numLines += 1
						lineArray.append(line2)


lineChoice = random.randint(0, numLines - 1)
print lineArray[lineChoice]
