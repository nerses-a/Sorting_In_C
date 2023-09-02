#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Для генерации произвольного массива

void outputArray(int n, int *array);
void generateArray(int n, int *array, int min, int max);

int main() {
    int n;            // Количество элементов массива
    scanf("%d", &n);  // Считываем n
    printf("%d\n", n);
    int *array = (int *)malloc(n * sizeof(int));  //  Выделяем память под массив

    // inputArray(n, array);
    generateArray(n, array, 0, 10000);
    outputArray(n, array);

    free(array);  // чистим выделеннвй память
    return 0;
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

void generateArray(int n, int *array, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}
