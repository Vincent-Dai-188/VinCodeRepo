#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 
 * int getopt (int argc, char *const *argv, const char *options)
 * header file: unistd.h
 * https://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html
 *
 * "options" argument: 
 * An option character in this string can be followed by a colon (‘:’) to 
 * indicate that it takes a required argument.
 * If an option character is followed by two colons (‘::’), its argument  
 * is optional; this is a GNU extension. 
 *
 * Usage sample-1: $ ./getopt -a -b 8 -c 15 
 * Usage sample-2: $ ./getopt -a -b 8 -c15
 */

int main(int argc, char *argv[])
{
    int result;
    int v_b, v_c;
   
    // Set opterr to zero, then getopt does not print any messages,
    // but it still returns the character ? to indicate an error. 
    opterr = 0;

    while( (result = getopt(argc, argv, "ab:c::")) != -1 )
    {
        switch(result)
        {
            case 'a':
                printf("option '-a' detected.\n");
                break;
            case 'b':
                v_b = atoi(optarg);
                printf("option '-b' detected, argument = %d.\n", v_b);
                break;
            case 'c':
                v_c = atoi(optarg);
                printf("option '-b' detected, argument = %d.\n", v_c);
                break;
            case '?':
                printf("result=?, optopt=%c, optarg=%s\n", optopt, optarg);
                break;
        }
    }

    return 0;
}
