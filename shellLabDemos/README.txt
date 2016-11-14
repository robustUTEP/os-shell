A. Use saferFork:

Note that if a process (or worse, its descendents) repeatedly call
fork(), the system will quickly become saturated with processes.  The
function saferFork (see saferFork.c) prints a message and then waits 5
seconds prior to calling fork().  I suggest using it so that you will
be able to stop processes from gobbling up resources.

B: Killing errant programs

You can send the "KILL" signal to processes you own.  Kill signals,
which can not be caught or ignored, causes processes to immediately
exit.  

The "kill" program (/bin/kill) takes two arguments:
    /bin/kill signal pid
You can use the "ps" program to determine the pid of processes (see
    man ps
for details) -- or (on most systems) you can specify "-1", which
selects all processes.  Of course, a "kill -KILL -1" will also kill
your login shell, thus logging you out.

Finally, SIGKILL (-KILL) is signal number 9, and therefore
    kill -9 -1
is equivalent to 
    kill -KILL -1.

In contrast control-c sends SIGINT (-INT, for interrupt), which can be
caught or ignored, see "man 2 signal" ("M-X man <cr> 2 signal" for emacs users).  

C. What to do if you can't fork do to using too many processes?
   1. login (if you can), and then "exec kill -9 -1" (exec causes the
   shell not to fork before "exec"ing a command.)
or 2. get an administrator to kill your processes.  Bring them cookies too.
or 3. reboot the machine
