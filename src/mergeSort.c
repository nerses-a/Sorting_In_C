#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputArray(int n, int *array);
void outputArray(int n, int *array);
void merjeSort(int firstElement, int lastElement, int *array);
void merje(int newN, int ptr1, int ptr2, int lastElement1, int lastElement2, int *array, int *newArray);
void copySortedArray(int firstElement, int lastElement, int *array, int *newArray);

int main() {
    int n;            // Количество элементов массива
    scanf("%d", &n);  // Считываем n

    int *array = (int *)malloc(n * sizeof(int));  //  Выделяем память под массив

    inputArray(n, array);
    clock_t startTime = clock();

    merjeSort(0, n - 1, array);

    clock_t endTime = clock();

    outputArray(n, array);

    freopen("/dev/tty", "r", stdin);

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

void merjeSort(int firstElement, int lastElement, int *array) {
    if (lastElement - firstElement < 1) {
        return;
    }

    int lastElement1 = (lastElement + firstElement) / 2;
    int firstElement2 = (lastElement + firstElement) / 2 + 1;

    merjeSort(firstElement, lastElement1, array);
    merjeSort(firstElement2, lastElement, array);

    int newN = lastElement - firstElement + 1;
    int *newArray = (int *)malloc(newN * sizeof(int));

    int ptr1 = firstElement;
    int ptr2 = firstElement2;

    merje(newN, ptr1, ptr2, lastElement1, lastElement, array, newArray);
    copySortedArray(firstElement, lastElement, array, newArray);

    free(newArray);
}

void merje(int newN, int ptr1, int ptr2, int lastElement1, int lastElement2, int *array, int *newArray) {
    for (int i = 0; i < newN; ++i) {
        if (ptr1 > lastElement1) {
            newArray[i] = array[ptr2];
            ++ptr2;
        } else if (ptr2 > lastElement2) {
            newArray[i] = array[ptr1];
            ++ptr1;
        } else if (array[ptr1] > array[ptr2]) {
            newArray[i] = array[ptr2];
            ++ptr2;
        } else {
            newArray[i] = array[ptr1];
            ++ptr1;
        }
    }
}

void copySortedArray(int firstElement, int lastElement, int *array, int *newArray) {
    for (int i = firstElement; i < lastElement + 1; ++i) {
        array[i] = newArray[i - firstElement];
    }
}
