#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputArray(int n, int *array);
void outputArray(int n, int *array);
void quickSort(int firstElement, int lastElement, int *array);
void swap(int *i, int *j);

int main() {
    int n;            // Количество элементов массива
    scanf("%d", &n);  // Считываем n

    int *array = (int *)malloc(n * sizeof(int));  //  Выделяем память под массив

    inputArray(n, array);

    clock_t startTime = clock();

    quickSort(0, n - 1, array);

    clock_t endTime = clock();

    outputArray(n, array);

    freopen("/dev/tty", "w", stdout);

    double executionTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Sorting took %f seconds\n", executionTime);

    free(array);  // чистим выделеннвй память

    return 0;
}

int inputArray(int n, int *array) {
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
}

void outputArray(int n, int *array) {
    for (int i = 0; i < n; ++i) {
        printf("%d", array[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void quickSort(int firstElement, int lastElement, int *array) {

    if (firstElement >= lastElement) {
        return;
    }

    int ptr1 = firstElement;
    int ptr2 = lastElement;
    int pivot = array[(firstElement + lastElement) / 2];

    do {
        while (array[ptr1] < pivot) ptr1++;
        while (array[ptr2] > pivot) ptr2--;

        if (ptr1 <= ptr2) {
            swap(array + ptr1, array + ptr2);
            ptr1++;
            ptr2--;
        }

    } while (ptr1 <= ptr2);

    quickSort(firstElement, ptr2, array);
    quickSort(ptr1, lastElement, array);

}
