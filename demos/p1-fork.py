#! /usr/bin/env python3

import os, sys, time

pid = os.getpid()

os.write(1, ("About to fork (pid:%d)\n" % pid).encode())

rc = os.fork()

if rc < 0:
    os.write(2, ("fork failed, returning %d\n" % rc).encode())
    sys.exit(1)
elif rc == 0:                   # child
    for i in range(5):
        os.write(1, ("I am child.  My pid==%d.  Parent's pid=%d\n" % (os.getpid(), pid)).encode())
        time.sleep(1)
else:                           # parent (forked ok)
    for i in range(5):
        os.write(1, ("I am parent.  My pid=%d.  Child's pid=%d\n" % (pid, rc)).encode())
        time.sleep(1)
    
