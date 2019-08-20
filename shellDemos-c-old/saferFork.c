#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/* note that a pid_t is normally an int */ 
pid_t saferFork()
{
  fprintf(stderr, "process <%d> calling fork() in 5 seconds...", getpid());
  sleep(5);
  fprintf(stderr, "calling fork now!\n");
  return fork();
}

int 
main() {
  pid_t forkVal = saferFork();
  printf("forkVal=%d\n", forkVal);
  return 0;
}
