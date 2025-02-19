#!/bin/zsh

tr -s ' ' < words.txt | tr ' ' '\n' | sort | uniq -c | sed -E 's/^[[:space:]]+//' | sort -k1,1nr | sed -E 's/([0-9]+) ([a-z]+)/\2 \1/'
