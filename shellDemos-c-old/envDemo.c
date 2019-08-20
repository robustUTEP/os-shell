#include "stdio.h"
int
main(int argc, char **argv, char**envp) 
{
  int i;
  for (i=0; envp[i] != (char*)0; i++) 
    printf("envp[%d] = \"%s\"\n", i, envp[i]);
  return 0;
} 
