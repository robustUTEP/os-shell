main(int argc, char **argv, char**envp) 
{
  int i;
  for (i=0; i < argc; i++) 
    printf("argv[%d] = \"%s\"\n", i, argv[i]);
} 

