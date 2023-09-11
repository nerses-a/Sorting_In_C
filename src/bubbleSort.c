#include <stdio.h>
#include <stdlib.h>

int inputArray(int n, int *array);
void outputArray(int n, int *array);
void bubbleSort(int n, int *array);
void swap(int *i, int *j);

int main() {
    int n;            // Количество элементов массива
    scanf("%d", &n);  // Считываем n

    int *array = (int *)malloc(n * sizeof(int));  //  Выделяем память под массив

    inputArray(n, array);

    bubbleSort(n, array);

    outputArray(n, array);

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

void bubbleSort(int n, int *array) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Если текущий элемент больше следующего, меняем их местами
                swap(array + j, array + j + 1);
            }
        }
    }
}

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
