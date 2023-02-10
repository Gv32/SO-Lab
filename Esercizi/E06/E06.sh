#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Errore passaggio parametri"
    exit 1
fi

while read row
do
    n=$(echo $row | wc -w)

    let resto=n%2
    if [ $resto -eq 1 ]
    then
        echo $row | tr [A-Z] [a-z]
    else
        echo $row | tr [a-z] [A-Z]
    fi
done < $1