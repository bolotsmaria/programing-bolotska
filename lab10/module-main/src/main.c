#include <stdio.h>
#include "lib.h"

/** 
        @file main.c 
        №23 Визначити чи є задане число простим 
        @author Bolotska M. 
*/

int main()
{
	int x;
	printf("Введіть число: ");
	scanf("%d", &x);
	printf("Значення: %d\n", isPrime(x));
	return 0;
}
