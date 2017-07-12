#include "stdio.h"

int x[] = { 6, 8, 9, 4, 2, 35, 12, 97, 63, 7, 11, 5, 18, 3, 52, 61, 0, 47, 39 };
const int LEN = sizeof(x)/sizeof(int);

typedef enum bool_s {false, true} bool;

void print_list(int data[], int length)
{
    for (int i=0;i<length;i++)
        printf("%d ", data[i]);
    printf("\n");
}

void bubble_sort(int data[], int length)
{
	int i, n;
	int tmp;

	n = 1;
	while (n < length)
	{
		for (i=0;i<(length-n);i++)
		{
			if (data[i] > data[i+1])
			{
				tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			}
		}
		printf("  <%02d> adjusted list: ", n);
    	print_list(x, LEN);
		n++;
	}
}

int main(int argc, char *argv[])
{
	printf("\nUnsorted list: ");
    print_list(x, LEN);
    printf("\n");

	bubble_sort(x, LEN);
    
	printf("\nSorted list: ");
    print_list(x, LEN);
    printf("\n");

    return 0;
}
