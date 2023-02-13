#!/bin/bash

max=0
nomem=""

for nome in $(ps -e | tr -s " " | cut -d " " -f 5)
do
    i=${#nome}
    if [ $i -gt $max ]
    then
        max=$i
        nomem=$nome
    fi
done
echo "Il nome con lunghezza massima e' $nomem"