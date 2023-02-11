#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Errore passaggio parametri"
    exit 1
fi

dir="./etc/passwd"
dirutente=$(cat $dir | grep "$1" | cut -d ":" -f 6)
#rm -R $dirutente

cat $dir | grep -v "$1" > "tmp"
mv tmp $dir