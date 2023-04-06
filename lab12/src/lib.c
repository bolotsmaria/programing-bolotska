#include "lib.h"
#include <stdio.h>

void print_pascal_triangle(int rows) {	//Оголошення функції print_pascal_triangle, яка приймає цілочисельний параметр rows та не повертає жодного значення.
  int i, j, k, coef;	//Оголошення змінних цілочисельного типу: i, j, k та coef.
 
  for (i = 0; i < rows; i++) {	//Цикл for, який повторюється rows разів та збільшує змінну i на 1 на кожній ітерації.

    coef = 1;	//Присвоєння значення 1 змінній coef.
    for (j = 1; j < rows - i; j++) {
      printf(" ");	//Виведення в консоль j пробілів, де значення змінної j збільшується на 1 на кожній ітерації, поки j < (rows - i).
    }
    for (k = 0; k <= i; k++) {
      printf("%d ", coef);
      coef = coef * (i - k) / (k + 1);	//Виведення в консоль коефіцієнту coef та обчислення наступного значення coef, де значення змінної k збільшується на 1 на кожній ітерації, поки k <= i.
    }
    printf("\n");	//Виведення в консоль символу нового рядка.
  }
}

/*
Рекурсивний спосіб
#include "lib.h"
#include <stdio.h>

void print_spaces(int n) {
  if (n == 0) {
    return;
  }
  printf(" ");
  print_spaces(n - 1);
}

void print_coefficients(int row, int col, int coef) {
  if (col > row) {
    printf("\n");
    return;
  }
  printf("%d ", coef);
  print_coefficients(row, col + 1, coef * (row - col) / (col + 1));
}

void print_pascal_triangle_helper(int rows, int current_row) {
  if (current_row > rows) {
    return;
  }
  print_spaces(rows - current_row);
  print_coefficients(current_row - 1, 0, 1);
  print_pascal_triangle_helper(rows, current_row + 1);
}

void print_pascal_triangle(int rows) {
  print_pascal_triangle_helper(rows, 1);
}
