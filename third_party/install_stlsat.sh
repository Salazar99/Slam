#!/bin/sh
######################################################################
#stlsat requires z3 -- make sure to run the install_z3.sh script first
######################################################################


#install rust toolchain for stlsat
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

#install stlsat - fix branch is temporary until PR is merged
cargo install --git https://github.com/ZamponiMarco/stlsat.git --branch fix