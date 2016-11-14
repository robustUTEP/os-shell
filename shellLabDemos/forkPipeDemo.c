#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>		/* for calloc */
#include <unistd.h> 		/* for pipe */
#include <stdio.h>		/* for printf */

int main(int argc, char**argv, char**envp)
{
  int pid;
  int *pipeFds;
  pipeFds = (int *) calloc(2, sizeof(int));
  pipe(pipeFds);

  pid = fork();
  if (pid == 0) {		/* child */

    printf("child: fork returned %d\n", pid);

    close(1);
    dup(pipeFds[1]);
    close(pipeFds[0]); close(pipeFds[1]);

    printf("hello from child");
    exit(2);

  } else { 			/* parent */

    int waitVal, waitStatus;
    char buf[100];
    int childStatus; 
    printf("parent: child's pid=%d\n", pid);
    
    close(0);
    dup(pipeFds[0]);
    close(pipeFds[0]); close(pipeFds[1]);
    
    fgets(buf, 100, stdin);
    printf("parent read <%s> from child\n", buf);

    waitVal = waitpid(pid, &waitStatus, 0);
    if (waitVal == pid) {
      printf("child exited with value %d, %d\n", waitStatus, WEXITSTATUS(waitStatus));
    } else {
      printf("strange: waitpid returned %d\n", waitVal);
    }
    return 0;
  }
}
