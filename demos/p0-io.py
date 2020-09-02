#! /usr/bin/env python3

import os, sys, re


fdOut = os.open("p0-output.txt", os.O_CREAT | os.O_WRONLY)
fdIn = os.open("p0-io.py", os.O_RDONLY)

print(f"fdIn={fdIn}, fdOut={fdOut}");

# note that
#  fd #0 is "standard input" (by default, attached to kbd)
#  fd #1 is "standard ouput" (by default, attached to display)
#  fd #2 is "standard error" (by default, attached to display for error output)

lineNum = 1
while 1:
    input = os.read(fdIn, 10000)  # read up to 10k bytes
    if len(input) == 0: break     # done if nothing read
    lines = re.split(b"\n", input)
    for line in lines:
        strToPrint = f"{lineNum:5d}: {line.decode()}\n"
        os.write(fdOut, strToPrint.encode()) # write to output file
        os.write(1    , strToPrint.encode()) # write to fd1 (standard output)
        lineNum += 1
        
