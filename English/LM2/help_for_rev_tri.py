import os
import sys

infile = open("/home/skomarag/Desktop/LM/train/text.txt", "r")
lines = infile.readlines()
for line in lines:
    line_list = line.split()
    line_list.reverse()
    line = ' '.join(line_list)
    print line