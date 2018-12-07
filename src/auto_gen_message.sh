#!/bin/bash

java -jar CodeGenCmdLine.jar update_with_name=true select_from_all_files=true emcpos.h emctool.h emc_nml.hh -o emc_nml.cc
