#include "lib.h"
#include <stdio.h>

int main() {	// Оголошення головної функції main().
  int rows;	// Оголошення змінної rows для зберігання введеного користувачем значення - кількості рядків трикутника Паскаля.

  printf("Enter the number of rows to generate for Pascal's triangle: ");	// Виведення запрошення для користувача на введення кількості рядків трикутника Паскаля.
  scanf("%d", &rows);	// Зчитування значення кількості рядків трикутника Паскаля, яке введене користувачем.

  print_pascal_triangle(rows);	// Виклик функції print_pascal_triangle() з передачею в неї значення кількості рядків трикутника Паскаля.

  return 0;
}
/*
Рекурсивний спосіб
#include "lib.h"
#include <stdio.h>

void print_pascal_triangle_recursive() {
  int rows;

  printf("Enter the number of rows to generate for Pascal's triangle: ");
  scanf("%d", &rows);

  print_pascal_triangle(rows);
}

int main() {
  print_pascal_triangle_recursive();

  return 0;
}

