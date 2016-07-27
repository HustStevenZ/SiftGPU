#!/usr/bin/env python3
import sys
from os import system
from os import listdir
from os.path import isfile, join
from subprocess import call
mypath=sys[1]
onlyfiles=[]
for f in listdir(mypath):
    if(f.endswith('.sift')):
        # print(join(mypath, f))
        onlyfiles.append(join(mypath, f))

number = onlyfiles.__len__()

for i in range(number-1):
    for j in range(number-(i+1)):
        # print(str(i)+" "+str(i+1+j))
        # print(onlyfiles[i]+' '+onlyfiles[i+1+j])
        arg=onlyfiles[i]+' '+onlyfiles[i+1+j]
        cmd='./build/MatchConsole'
        cmdstr = cmd+ " "+ arg
        system(cmdstr)