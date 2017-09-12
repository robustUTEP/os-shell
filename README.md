## Theory of Operating Systems

## Unix Shell

## Assignment Part 1

Using your tokenizer and the system calls fork(), exec(), and wait() create a simple shell that:

- prints a command prompt which is "$ " and waits for the user to enter a command
- parse the command using your tokenizer 
- create a child process that uses execve to run the command with its arguments.  
- If an absolute path is not specified, your shell should instead find it using the $PATH environment variable.
- the parent process should wait for the child to terminate before printing another command prompt.
- print "command not found" if the command is not found
- if the command fails (with a non-zero exit value N), your shell should print "Program terminated with exit code N."
- empty commands should do nothing
- the "exit" command should cause your shell to terminate.

We have provided a program called tt (tokenizer tester) which is meant to test your tokenizer. Compile and add this program to your PATH 
environment variable before running your shell.

Here's an example output of tt:

$ tt  &nbsp;&nbsp;&nbsp;hello&nbsp;&nbsp;&nbsp;&nbsp;world&nbsp;&nbsp;&nbsp;&nbsp;peace&nbsp;&nbsp;&nbsp;&nbsp;<br />
argc = 4<br />
argv[ 0 ] = tt<br />
argv[ 1 ] = hello<br />
argv[ 2 ] = world<br />
argv[ 3 ] = peace<br />
<br />
$

## Assignment Part 2

In this lab, you will create a user shell in the C programming language that can understand:

- simple commands (e.g. $ /bin/ls or $ ls )
- simple pipes (e.g. $ /bin/ls | /bin/sort -r)
- background tasks (e.g. $ find /etc -print & )
-  "cd" ## for "cd" you will need to lookup the library routine "chdir" in the (online) unix manual

You have additional components required for testing this part of the shell. See the section below for further details.

optional (except for grad students)
- redirecting input and output (e.g. $ ls > /tmp/files.txt)
- setting environment variables: "var=value" 
- expanding ~ at the beginning of a parameter
- expanding non-embedded environment variables (e.g. "echo $PATH")

optional for everyone
- command line editing using readline(3)
- expanding embedded environment variables (e.g. "echo ${HOME}/bin"
- expanding ~ within a parameter (e.g. "ls | dd of=~/files.txt")
- Programs that cannot be exec'd or terminate with errors (non-zero exit codes) should be reported.

Your lab must directly use the posix calls:

- pipe()
- fork()
- dup() or dup2()
- execve() (you cannot use execvp)
- wait()
- open() and close()
- chdir()

These system calls are documented in chapter 2 of the unix manual (e.g. $ man 2 fork).

In addition, your program should dynamically allocate memory using the
library calls malloc and free. You may (if you like) use calloc and
strdup which are part of the same library.

## Testing your lab

The OS Grading Team has created a testing harness for your shell lab
located in shell/testShell.sh.  

The tests will provide commands to your shells through standard input
(fd #0).  Those command sequences terminate with end-of-file.  Just
like bash, your shell should terminate when they read this
end-of-file. End-of-file is easy to detect as that a request to read()
more than zero bytes will transfer zero bytes.

If there is a PS1 (prompt string #1) environment variable, then your
shell's prompt should be its value.  This is used to suppress your
shell's prompt.  Otherwise, your shell can use any reasonable prompt
string.

To test this, try

  $ export PS1=""

before invoking your shell.

Note that the arch1 virtual machine's default value for PS1 is "[\u@\h
\W]$ " where bash substitutes \u with username, \h with hostname, and
\w with the current working directory.  

Your shell should not write extraneous messages to standard out 
(fd #1).  This is because our tester will be confused by that
information.  
It's fine to print such information to "standard error" (fd #2).

## Useful Snippets

The shellLabDemos contains several demonstration programs that
utilize the system calls and features necessary to implement your shell.

- argDemo: print command line arguments (how argv works)
- envDemo: print the contents of envp (how envp works)
- forkPipeDemo: a short program that uses fork & pipe
- execDemo.c: a short program using exec


## Grading

Our TA will assess:the following aspects of your project:

- documentation/readability/software engineering
- exec properly
- fork properly (shell does not terminate with commands...). Includes checking if program failed (exit code != 0).
- pipe between commands
- background commands
- proper use of PATH environment variable
- proper functioning of environment variables
- proper functioning of change-directory builtin (cd)
