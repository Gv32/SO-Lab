#!/bin/bash

echo "inserisci il nome del processo"
read processo
echo "inserisci tempo"
read tempo

cz=0

while [ cz -le 5 ]
do
    linea = $(ps -el | grep $processo)
    stato=$(echo $linea | cut -d ' ' -f 9)

    if [$stato -eq "Z"]
    then
        let cz=cz+1
    else
        cz=0
    fi

    if [ $cz -eq 5 ]
    then
        pid=$(echo $linea | cut -d ' ' -f 2)
        kill -9 pid
        exit 0
    fi

    sleep $tempo
done