#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

typedef enum bool_s {false, true} bool;

long long Fibonacci(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    return Fibonacci(n-1) + Fibonacci(n - 2);
}       

long long Fibonacci_loop(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    long long fibMinus1 = 1;
    long long fibMinus2 = 0;
    long long fibN = 0;
    for (int i=2;i<=n;i++)
    {
        fibN = fibMinus1 + fibMinus2;
        fibMinus2 = fibMinus1;
        fibMinus1 = fibN;
    }

    return fibN;
}

int main(int argc, char *argv[])
{
    long long fibN = 0;
    int n = 10;
    bool need_Recur = false;
    
    int result;

    while( (result = getopt(argc, argv, "Rn:")) != -1 )
    {
        switch(result)
        {
            case 'R':
                need_Recur = true;
                break;
            case 'n':
                n = atoi(optarg);
                break;
            case '?':
                printf("Usage: ./fib_seq [-R] [-n <NUM>]\n");
                exit(2);
                break;
        }
    }

    if (need_Recur)
    {
        fibN = Fibonacci(n);
        printf("  Fibonacci_recur(%d) = %lld\n", n, fibN);
    }
    else
    {
        fibN = Fibonacci_loop(n);
        printf("  Fibonacci_loop(%d) = %lld\n", n, fibN);
    }    

    return 0;
}
