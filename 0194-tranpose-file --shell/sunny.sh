#!/bin/zsh

# Read from the file file.txt and print its transposed content to stdout.

i=1
ncols=$(head -n 1 file.txt | grep -o ' ' | wc -c | grep -E -o '[0-9]+')
ncols=$((ncols + 1))
while [ $i -le $ncols ]
do
    col="$(cut -d' ' -f$i file.txt)"
    [ -z "$col" ] && break
    echo "$col" | tr '\n' ' '
    echo ''
    i=$((i + 1))
done

