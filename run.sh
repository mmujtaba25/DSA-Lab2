#!/bin/bash

mkdir -p out/

g++ "$1" -o out/bin
./out/bin
