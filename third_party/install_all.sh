#!/bin/bash

if [ $# -eq 0 ]
then
    bash install_antlr.sh
    bash install_z3.sh
    bash install_stlsat.sh 
else
    installPrefix="$1"
    bash install_antlr.sh "$installPrefix"
    bash install_z3.sh "$installPrefix"
    bash install_stlsat.sh "$installPrefix"
fi


