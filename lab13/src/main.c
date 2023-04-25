#include "lib.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main() {
   char text[BUFFER_SIZE];

   printf("Введіть текст: ");
   fgets(text, BUFFER_SIZE, stdin);
   text[strlen(text)-1] = '\0';

   int count = count_digits(text, BUFFER_SIZE);

   printf("Знайдено цифр: %d\n", count);
   return 0;
}
