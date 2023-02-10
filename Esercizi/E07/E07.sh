#!/bin/bash

if [ $# -ne 6 ]
then
    echo "Errore passaggio parametri"
    exit 1
fi

i=0

while read line
do
    i=0
    while [ $i -ne $4 ]
    do
        echo -n "$5"
        let i=i+1
    done
    echo -n " "
    i=0

    for word in $line
    do
        if [ $word = $2 ]
        then
            parola=$3
            echo -n "$parola "
        else
            parola=$word
            echo -n "$parola "
        fi
    done

    while [ $i -ne $4 ]
    do
        echo -n "$5"
        let i=i+1
    done

    echo ""

done < $1 > $6