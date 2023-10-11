#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap = gap / 2) // Corrected loop condition
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j = j - gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}

int main()
{
    int arr[] = {7, 4, 8, 10, 16, 6, 11, 3, 1, 2};
    printf("\nBefore Sorting.........");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    shellSort(arr, 10);
    printf("\nAfter Sorting.........");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    getchar(); // Use getchar() instead of getch()
    return 0;
}

