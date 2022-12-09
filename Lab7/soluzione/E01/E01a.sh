#!/bin/bash

if [ $# -ne 3 ]
then
    echo "Errore numero parametri"
    exit 1
fi

if [ ! -d $1 ]
then
    echo "creazione direttorio"
    mkdir $1
fi

if [ ! -f $3 ]
then
    echo "creazione file"
    touch $3
fi

grep -H -r -n "$2" $1 | sort -r -t ':' -k 1 -k 2n > $3