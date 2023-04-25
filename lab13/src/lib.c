#include "lib.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 1000

int count_digits(char *text, int size){
   int count = 0;
   char *p;

   for (p = text; *p != '\0' && p < text + size - 1; p++) {
      if (isdigit(*p)) {
         count++;
      }
   }

   return count;
}

