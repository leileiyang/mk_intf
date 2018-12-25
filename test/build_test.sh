#!/bin/bash

g++ -Wall -std=c++11 main.cc -lgtest -L../build -lmkmsg -lrcs -lpthread -o test
export LD_LIBRARY_PATH=../build
