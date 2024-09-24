#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(double* xp, double* yp) {
    double temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(double arr[], int n) {
    int i, j;
    bool swapped;

    i = 0;
    start_outer:
    if (i >= n - 1) goto end_outer;
    j = 0;
    swapped = false;

    start_inner:
    if (j >= n - i - 1) goto end_inner;
    if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
    }
    j++;
    goto start_inner;

    end_inner:
    if (!swapped) goto end_outer;
    i++;
    goto start_outer;

    end_outer:
    return;
}

void printArray(double* arr, int size) {
    int i;
    i = 0;
    goto loop_start;
    loop_body:
    printf("%lf ", arr[i]);
    i++;
    if (i < size) goto loop_body;
    printf("\n");
    return;
    loop_start:
    goto loop_body;
}

double* read_array(int* size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);
    double* m = malloc(sizeof(double) * (*size));
    int i;
    i = 0;
    goto loop_start;
    loop_body:
    printf("m[%d]=", i);
    scanf("%lf", &m[i]);
    i++;
    if (i < *size) goto loop_body;
    return m;
    loop_start:
    goto loop_body;
}

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

