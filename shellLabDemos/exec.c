#include <unistd.h>
#include <stdio.h>

int
main(int argc, char**argv, char**envp) {
    int retVal = execve(argv[1], &argv[1], envp);
    // note: the following statements will not be executed
    // if exec succeeded
    fprintf(stderr, "%s: exec returned %d\n", argv[0], retVal);
    return 0;
}
