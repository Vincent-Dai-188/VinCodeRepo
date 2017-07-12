#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x[] = { 6, 8, 9, 4, 2, 35, 12, 97, 63, 7, 11, 5, 18, 3, 52, 61, 0, 47, 39 };
const int LEN = sizeof(x)/sizeof(int);

typedef enum bool_s {false, true} bool;

static void print_list(int data[], int len)
{
    for (int i = 0; i < len; i++)
		printf("%-2d ", data[i]);
	printf("\n");
}

/*
 * Merge sorted list_left[] and list_right[] to list_final[]
 */
void merge(int list_final[], int list_left[], int len_left, int list_right[], int len_right)
{
	int index_left = 0;
    int index_right = 0;
	int index_final = 0;

    /*printf("    - Left_list: "); 
    print_list(list_left, len_left);
    
    printf("    - Right_list: "); 
    print_list(list_right, len_right);*/

	while (index_left < len_left && index_right < len_right)
    {
		if (list_left[index_left] < list_right[index_right])
			list_final[index_final++] = list_left[index_left++];
		else
			list_final[index_final++] = list_right[index_right++];
	}

	while (index_left < len_left)
		list_final[index_final++] = list_left[index_left++];

	while (index_right < len_right)
		list_final[index_final++] = list_right[index_right++];
}

void merge_sort(int data[], int len)
{
    int middle, len_left, len_right;
    int *buf_left, *buf_right;
    int i;
    if (len > 1)
    {
        middle = len / 2;
        len_left = middle;
        len_right = len - middle;
        buf_left = (int *)malloc(sizeof(int) * len_left);
        if (buf_left == NULL) {
            printf("Failed to malloc buffer!\n");
            return;
        }
        for(i=0;i<len_left;i++)
            buf_left[i] = data[i];

        buf_right = (int *)malloc(sizeof(int) * len_right);
        if (buf_right == NULL) {
            printf("Failed to malloc buffer!\n");
            return;       
        }
        for(i=0;i<len_right;i++)
            buf_right[i] = data[len_left + i];
    
        /*printf("    >> Left_list: "); 
        print_list(buf_left, len_left);
        
        printf("    >> Right_list: "); 
        print_list(buf_right, len_right);*/

        merge_sort(buf_left, len_left);	    // To sort the left side
        merge_sort(buf_right, len_right);	// To sort the right side
        
        merge(data, buf_left, len_left, buf_right, len_right);  // Merge the two sorted parts

        printf("  Merged_list: "); 
        print_list(data, len);

        if (buf_left != NULL)
            free(buf_left);
        if (buf_right != NULL)
            free(buf_right);
    }
}

int main(int argc, char *argv[])
{
	printf("Unsorted list: "); 
    print_list(x, LEN);

	merge_sort(x, LEN);

	printf("Sorted list: "); 
    print_list(x, LEN);

	return 0;
}
