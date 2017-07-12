#include "stdio.h"

int x[] = { 6, 8, 9, 17, 1, 35, 12 };
const int LEN = sizeof(x)/sizeof(int);

typedef enum bool_s {false, true} bool;

void print_list(int data[], int left, int right)
{
    if (left >=right)
	return;

    for (int i=left;i<=right;i++)
        printf("%d ", data[i]);
    printf("\n");
}

int mid_square(int data[], int left, int right)
{
	int pivotpos;
	int mid = (right - left) / 2;

	printf(" x[%d] = %d, x[%d] = %d, x[%d] = %d\n", left, data[left], mid, data[mid], right, data[right]);
	if ( ((data[mid] <= data[left]) && (data[left] <= data[right])) ||
			((data[right] <= data[left]) && (data[left] <= data[mid])) )
		return left;

	if ( ((data[left] <= data[mid]) && (data[mid] <= data[right])) ||
			((data[right] <= data[mid]) && (data[mid] <= data[left])) )
		return mid;

	if ( ((data[left] <= data[right]) && (data[right] <= data[mid])) ||
			((data[mid] <= data[right]) && (data[right] <= data[left])) )
		return right;
}

int main(int argc, char *argv[])
{
	int mid_V;
    
	printf("\nUnsorted list: ");
    print_list(x, 0, LEN-1);
    printf("\n");

    mid_V = mid_square(x, 0, LEN - 1);

    
    printf("\n  mid_square = %d ([%d])\n", x[mid_V], mid_V);

    return 0;
}
