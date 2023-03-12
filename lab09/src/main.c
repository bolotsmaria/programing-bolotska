#include <stdio.h>
#include "lib.h"

int main()
{
    int x;
    printf("Введіть число: ");
    scanf("%d", &x);
    printf("Значення: %d\n", isPrime(x));
    return 0;
}
