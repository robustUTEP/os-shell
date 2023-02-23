## Unix Shell

Your goal for this lab is to build a user shell for a Unix operating
system. In general, you are expected to mimic some of the behaviors of
the bash shell you have been using. The provided testing
harness will compare the output of your shell to the output of the
bash shell to test for correctness.

### Requirements

Your shell should meet the following requirements:

1. Prints a prompt string specified by shell variable PS1 when expecting a command (if PS1 is not set, the default prompt should be "$ ").
2. Accepts the standard unix command shell syntex for specifying commands and parameters
	* Your shell should create a child process that uses execve to run the command with its parameters.  
	* If an absolute path is not specified, your shell should instead find it using the $PATH environment variable.
	* The parent process should wait for the child to terminate before printing another command prompt.
3. Handles expected user error.
	* Prints "command not found" if the command is not found. For example, if the user tries to run program `lx` and this program doesn't exist, the shell should respond with "lx: command not found".
	* If the command fails (with a non-zero exit value N), your shell should print "Program terminated with exit code N."
4. Provides the following built-in commands.
	* The "exit" command should cause your shell to terminate.
	* Change directories with the "cd" command.
5. Redirection of input and output (e.g. $ ls > /tmp/files.txt).
6. Simple pipes (e.g. $ ls | sort -r).
7. Background tasks (e.g. $ find /etc -print & )

### Python Libraries

You should only need the following python libraries to complete the lab:
- os
- sys
- re

In particular, you should directly use the posix calls:

- pipe()
- fork()
- dup() or dup2()
- execve() (you cannot use execvp)
- wait()
- open() and close()
- chdir()

### Testing your lab

A testing harness for your shell has been to provided to help ensure correct functionality. The bash script is located in shell/testShell.sh.

The tests will provide commands to your shells through standard input (fd #0) and will terminate with end-of-file. Just like bash, your shell should terminate when they read this end-of-file. 

Bash uses a local variable called PS1 to store its prompt string. If you recall from using the arch1 virtual machine, the prompt string looked something like "student@localhost:/home>". This is because the default value for PS1 is "\u@\h:\W>" where bash substitutes \u with username, \h with hostname, and \w with the current working directory. _If there is a PS1 (prompt string #1) environment variable, then your shell's prompt should be its value._ The testing harness will set PS1 to an empty string to remove any differences caused by the prompt string when comparing the output of your shell to the output of bash.

To test this effect per command, try the following:

```bash
  (export PS1=""; ./shell.py)
```

### Learning Outcomes

* compose a executable python script
* parse commands
   * simple w/ args
   * input/output redirection
   * pipes
* fd io (read, write, lseek)
* fd connect: create/open files and pipes
* fd lifecycle:
   * close, dup, set_inheritance,
   * ability to replumb fd's
* process lifecycle: create, terminate, wait for child to terminate
* run an arbitrary program by its filename
* env vars:
   * what they are, why exist
   * can use PATH & PS1 

*Important!*
Your shell should not write extraneous messages to standard out (fd #1). This is because our tester will be confused by that
information. It's fine to print such information to "standard error" (fd #2).

### Useful Snippets

The demos directory contains several small programs that utilize the system calls and features necessary to implement your shell.

