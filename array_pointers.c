#include "stdio.h"
#include "string.h"

/*
  Output:
  &str1 != &str2

  p_str3 == p_str4

  str1 is same as str2

  *str3 is same as *str4
*/

int main(int argc, char *argv[])
{
    int ab[4][4]={ {1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15} };
    int i, j;
    char str1[] = "hello, world";
    char str2[] = "hello, world";
    char *p_str3 = "hello, world";
    char *p_str4 = "hello, world";

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("  %d\t", ab[i][j]);
        printf("\n");
    }

    printf("\nstr1[]: %s\n", str1);
    printf("str2[]: %s\n", str2);
    printf("*str3: %s\n", p_str3);
    printf("*str4: %s\n", p_str4);

    if (str1 == str2)
        printf("\n  &str1 == &str2\n");
    else
        printf("\n  &str1 != &str2\n");     // Not the same pointer addr

    if (p_str3 == p_str4)
        printf("\n  p_str3 == p_str4\n");   // Refer to the same addr (same constant string)
    else
        printf("\n  p_str3 != p_str4\n");

    if ( 0 == strcmp(str1, str2) )
        printf("\n  str1 is same as str2\n");       // Same content
    else
        printf("\n  str1 isn't same as str2\n");

    if ( 0 == strcmp(p_str3, p_str4) )
        printf("\n  *str3 is same as *str4\n");     // Same content
    else
        printf("\n  *str3 isn't same as *str4\n");

    return 0;
}
