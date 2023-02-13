#!/bin/bash

for file in $(find /home -name "*.c")
do
    nome=$(basename $file)
    cat $file | grep $nome

    if [ $? -eq 0 ]
    then
        mv $file $file"_new"
    fi
done