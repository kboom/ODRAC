#!/bin/bash

cmake -DPAPI_PREFIX=/home/rikkt0r/out
make
for x in 1 2 3 4 5 51 52 6 7 8 9 ; do
    echo "------ Solver $x TIME -------"
    ./OORA ${x} 0
    echo "------ Solver $x FLOPS 1 -------"
    ./OORA ${x} 1
    echo "------ Solver $x FLOPS 2 -------"
    ./OORA ${x} 2
done
