#include "signal.h"
#include "unistd.h"
#include <stdio.h>

int main(int argc, char**argv, char**envp)
{
  int sleepTime = 10;
  signal(SIGINT, SIG_IGN);
  signal(SIGHUP, SIG_IGN);

  while (sleepTime) {
    sleepTime = sleep(10);	/* sleep returns early if signal handled */
    if (sleepTime != 0)
      printf("sleep returned %d\n", sleepTime);
  }
  printf("exiting\n");
  return (0);
}

