#!/bin/bash

echo "Inserire nome direttorio"
read $direttorio

if [ $? -ne 0 ]
then
    echo "errore inserimento"
    exit 1
fi

if [ ! -d $direttorio ]
then
    echo "direttorio non essitente"
    exit 2
fi

for i in $(find -mindepth 2 $direttorio)
do
    nuovo=$(echo $i | tr [A-Z] [a-z])
    mv $i $nuovo
done