#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x[] = { 17, 26, 20, 44, 55, 31, 54, 77, 93 };
const int LEN = sizeof(x)/sizeof(int);
int sum = 0;

typedef enum bool_s {false, true} bool;

void print_list(int data[], int length)
{
    for (int i=0;i<length;i++)
        printf("%d ", data[i]);
    printf("\n");
}

void insert_sort(int data[], int length)
{
    int index = 1;
    int i, j;
    int currentV;

    while (index < length)
    {
        i = 0;
        currentV = data[index];
        while (i < index)
        {
            if (data[i] > data[index])
            {
                printf("    <%d> Insert '%d'([%d]) before '%d'([%d])\n", ++sum, data[index], index, data[i], i);
                j = index;
                while (j > i)
                {
                    data[j] = data[j-1];
                    j--;
                }
                data[i] = currentV;
                printf("\tcurrent list: ");
                print_list(x, LEN);
            }
            i++;
        }
        index++;        
    }
}

int main(int argc, char *argv[])
{
    printf("\nUnsorted list: ");
    print_list(x, LEN);
    printf("\n");

    insert_sort(x, LEN);
    
    printf("\nSorted list: ");
    print_list(x, LEN);
    printf("\n");

    return 0;
}
