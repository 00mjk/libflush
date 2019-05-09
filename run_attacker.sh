#!/bin/bash
cd build
te0="0016b7c0"
te1="0016b3c0"
te2="0016afc0"
te3="0016abc0"
crypto_lib="../test-suite/aes/shared_libs/libcrypto.so.1.0.0"
./attacker 600 1 250 $te0 $te1 $te2 $te3 $crypto_lib
