#include "stdio.h"

int x[] = { 6, 8, 9, 4, 2, 35, 12, 97, 63, 7, 11, 5, 18, 3, 52, 61, 0, 47, 39 };
//int x[] = { 6, 8, 9, 4, 2, 35, 12 };
const int LEN = sizeof(x)/sizeof(int);
static int indent_nm = 0;

typedef enum bool_s {false, true} bool;

void prntab(int n)
{
    for (int i=1;i<=n;i++)
        printf("     ");
}

void print_list(int data[], int left, int right)
{
    if (left >=right)
	return;

    for (int i=left;i<=right;i++)
        printf("%d ", data[i]);
    printf("\n");
}

void print_list_split(int data[], int left, int right, int pivotpos)
{
    if (left >=right)
        return;

    for (int i=left;i<=right;i++)
    {
	    if (pivotpos == i)
            printf("(%d) ", data[i]);
        else
            printf("%d ", data[i]);
    }
    printf("\n");
}

void swapdata(int data[], int index1, int index2, bool isPivot)
{
    static int sum = 0;
    int tmp;

    if (index1 != index2)
    {
    	sum++;
        prntab(indent_nm);
    	if (! isPivot)
            printf("   <%d> swap: [%d] <=> [%d]\n", sum, data[index1], data[index2]);
        else
            printf("   <%d> swap: [%d] <=> [%d]  * pivot_exchange *\n", sum, data[index1], data[index2]);
        tmp = data[index1];
        data[index1] = data[index2];
        data[index2] = tmp;
    }
}

/* 
 * The partition process will find the split point (pivot) and at the same time
 * move other items to the appropriate side of the list, either less than or 
 * greater than the pivot value. The split point position (i.e. the actual position  
 * where the pivot value belongs in the final sorted list) will be returned and
 * used to divide the list for subsequent calls to the quick sort.
*/
int partition(int data[], int left, int right)
{
    int pivotpos = right;       // Choose the last item as the pivot
    int pivot = data[pivotpos];

    /* 
     * 'storeIndex' points to the next position that should be used (exchanged) 
     * to store an item that is less than the pivot value. 
     */
    int storeIndex = left;

    /* 
     * 'index' is used to traverse the whole list except the pivot (i.e.
     * the last item in the list). 
     */
    int index = left; 

    prntab(indent_nm);
    printf(">> Partition for: ");
    print_list(data, left, right);
    
    while (index < right)
    {
        if (data[index] < pivot) 
        {
            if (index != storeIndex)
                swapdata(data, index, storeIndex, false);
            storeIndex++;
        }
        index++;
    }
    
    swapdata(data, pivotpos, storeIndex, true);
    
    prntab(indent_nm);
    printf("   Adjusted list: ");
    print_list_split(data, left, right, storeIndex);

    indent_nm++;
    return storeIndex;
}

void quick_sort(int data[], int left, int right)
{
    if (left < right)
    {
        int pos = partition(data, left, right);
        quick_sort(data, left, pos - 1);
        quick_sort(data, pos + 1, right);
        indent_nm--;
    }
}

int main(int argc, char *argv[])
{
    printf("\nUnsorted list: ");
    print_list(x, 0, LEN-1);
    printf("\n");

    quick_sort(x, 0, LEN-1);
    
    printf("\nSorted list: ");
    print_list(x, 0, LEN-1);
    printf("\n");

    return 0;
}
