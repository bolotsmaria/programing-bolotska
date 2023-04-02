#include "lib.h"
#include <stdio.h>

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int start = 0, end = 0;
    int max_sum = maxSubArray(arr, n, &start, &end);

    printf("Максимальная сумма подпоследовательности: %d\n", max_sum);
    printf("Подпоследовательность: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

