#!/bin/bash

if [ $# -ne 1 ]
then
    echo "numero di parametri errato"
fi

if [ ! -f $1 ]
then
    echo "parametro errato"
fi

numeroRighe=0
vMax=0
while read righe
do
    let numeroRighe=numeroRighe+1
    x=${#righe}
    if [ "$x" -gt "$vMax" ]
    then
        vMax=$x
    fi
done < $1

echo "numero righe $numeroRighe"
echo "lunghezza massima $vMax"