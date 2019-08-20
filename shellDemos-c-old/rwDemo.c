
#include <string.h>		/* for strlen */
#include <unistd.h>		/* for read, write */
#include <stdio.h>		/* for sprintf */

#define INBUFLEN 1000

int main()
{
    ssize_t amtRead;		/* ssize_t is some sort of integer */
    char buf[INBUFLEN];
    while ((amtRead = read(0, buf, (size_t)INBUFLEN)) > 0) {
	int i; 
	for (i = 0; i < amtRead; i++) {
	    char s[20];
	    sprintf(s, "[%d]:<%c>\n", i, buf[i]);
	    write(1, s, strlen(s));
	}
    }
}
