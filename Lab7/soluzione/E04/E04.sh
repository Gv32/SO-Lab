#!/bin/bash

file=$1
if [ $# -ne 1 ]
then
    echo "reinserire nome file"
    read file
    if [ $? -ne 0 ]
    then
        echo "errore nella read"
        exit 1
    fi

    if [ ! -f $file ]
    then
        echo "nessun file inserito"
        exit 2
    fi
fi

declare -A vettore

for parole in $(cat $file)
do
    vettore[$parole]=0
done

for parole in $(cat $file)
do
    tmp=${vettore[$parole]}
    let vettore[$parole]=tmp+1
done

for parole in ${!vettore[*]}
do
    echo "$parole: ${vettore[$parole]}"
done
