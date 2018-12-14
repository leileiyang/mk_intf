#!/bin/bash

g++ -Wall main.cc -lgtest -L../build -lmkmsg -lrcs -lpthread -o test
export LD_LIBRARY_PATH=../build
