#!/bin/bash

utente=$(whoami)

for file in $*
do
    if [ ! -d $file ]
    then
        nome=$file
        dimenzione=$(ls -l $file | tr -s " " |cut -d " " -f 5)
        al=$(ls -l $file | tr -s " " | cut -d " " -f 1 | grep -e "^-rw.*")
        echo "$nome $dimenzione $al"
    fi
    if [ ! -f $file ]
    then
        cd $file
        direttori=$(ls -l | grep -e "^d.*" | wc -l )
        echo "Numero di sottodirettori $direttori"
        echo "$(ls -l | tr -s " " | cut -f 9 -d " ")"
    fi
done