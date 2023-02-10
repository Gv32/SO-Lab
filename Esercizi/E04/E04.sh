#!/bin/bash

nr=0

while read row
do
    cont=0
    for word in $row
    do
        if [ $cont -eq $nr ]
        then
            i=${#word}
            let lunghezzatot=lunghezzatot+i
        fi
        let cont=cont+1
    done
    let nr=nr+1
done < file.txt
echo "Lunghezza massima $lunghezzatot"