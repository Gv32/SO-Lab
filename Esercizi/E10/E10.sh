#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Errore passaggio parametri"
fi

if [ ! -d $1 ]
then
    echo "Passare un direttorio"
fi

file=$(find $1 -type f -regextype "(^.)|(~$)")

for riga in $file
do
    i=$(basename $riga)
    num=${#i}
    let resto=$num%2

    if [ $resto -ne 0 ]
    do
        rm $file
    else
        mv $file $file".odd"
    fi
done