#!/bin/bash

max=0
i=0

for num in $(cat $1)
do
    echo "$num"
    i=${#num}
    if [ $i -gt $max ]
    then
        max=$i
        parola=$num
    fi
done
echo "la parola è $parola con lunghezza $max"