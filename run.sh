#!/bin/bash

for x in `ls zrodla` ; do
    cp zrodla/$x src/mm1.c
    cmake -DPAPI_PREFIX=/home/rikkt0r/out
    make
    echo "------  $x  -------"
    ./OORA
done
