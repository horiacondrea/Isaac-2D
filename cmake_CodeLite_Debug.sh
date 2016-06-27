#!/bin/bash

rm -rf build
mkdir build
cd build

cmake -G "CodeLite - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
