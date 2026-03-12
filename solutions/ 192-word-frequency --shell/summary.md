# Overview

Given a file of space-separated lowercase words, print out the frequencies of each word in descending order of frequency.  
This is a Shell-script problem, where a single-pipeline solution is preferred.

# Solution

Swap all spacebars for newlines to make each word appear on its own line.  
Use `sort` and `uniq` to count the words and `sed` to manipulate text into the right format.

# Trick

Use `uniq -c` to do the bulk of the counting work for you.  
We have to sort first, to group repeated words together for this to work.
