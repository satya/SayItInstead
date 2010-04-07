import os
import sys

infile = open("/home/skomarag/Desktop/HLM1/train/sample.txt", "r")
lines = infile.readlines()
for line in lines:
    line_list = line.split()
    line_list.reverse()
    line = ' '.join(line_list)
    print line
