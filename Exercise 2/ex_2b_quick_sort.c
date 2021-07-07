// c program to perform quick sort
#include <stdio.h>
 
void quicksort (int [], int, int);
 
void main()
{
    int arr[20];
    int n, i;
 
    printf("Enter the number of elements: ");
    scanf("%d", &n); 
    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quicksort(arr, 0, n - 1);
    printf("After applying quick sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void quicksort(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (arr[i] <= arr[pivot] && i <= high)
            {
                i++;
            }
            while (arr[j] > arr[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}
