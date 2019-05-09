#!/bin/bash

cd build
LD_PRELOAD=../test-suite/aes/shared_libs/libcrypto.so.1.0.0 ./daemon
