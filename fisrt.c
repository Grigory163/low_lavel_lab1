#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(double arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

// Function to print an array
void printArray(double arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%lf ", arr[i]);
    printf("\n");
}

double* read_array(int* size)
{
    printf("Enter the size of the array: ");
    scanf("%d", size);

    double* m = malloc(sizeof(double) * (*size));

    for (int i = 0; i < *size; i++) 
    {
        printf("m[%d]=", i);
        scanf("%lf", &m[i]);
    }
    return m;
}

// Driver program to test above functions
int main()
{
    int n;
    double *arr = read_array(&n);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    free(arr);
    return 0;
}