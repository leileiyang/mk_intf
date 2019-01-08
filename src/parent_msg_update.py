#!/usr/bin/python3

import os

old_dir = os.getcwd()
os.chdir(os.path.dirname(os.path.realpath(__file__)))

with open("emc_nml_raw.cc") as fin, open("emc_nml.cc", 'w') as fout:
    skip = False
    for line in fin:
        if 'void' in line and 'update' in line:
            # come across the message update function
            if 'EMC_STAT_MSG' in line: # come across the EMC_STAT_MSG update function
                skip = True
            else:
                skip = False

        if 'RCS_STAT_MSG' in line and 'update_stat_msg_base' in line:
            if skip:
                fout.write(line)
            else:
                fout.write('//' + line)
        else:
            fout.write(line)

os.remove('emc_nml_raw.cc')
os.chdir(old_dir)
