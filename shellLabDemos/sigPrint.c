#include "signal.h"
#include "unistd.h"
#include <stdio.h>

void handler(int signo)
{
  printf("signal %d caught\n", signo);
}

int main(int argc, char**argv, char**envp)
{
  int sleepTime = 10;
  signal(SIGINT, handler);
  signal(SIGHUP, handler);

  while (sleepTime) {
    sleepTime = sleep(10);
    if (sleepTime != 0)
    sleepTime = sleep(10);	/* sleep returns early if signal handled */
  }
  printf("exiting\n");
  return (0);
}

