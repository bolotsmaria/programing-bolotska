#include <stdio.h>
#include <math.h>

 
int taskFunc(int x) {				// задаємо функцію та змінну (х)

  if ( x < 1) {					// якщо x<1
    return x + 1;				// повертає х+1
  }

  return x - 1;
}

int main(void) {				// використовуємо void як пустий вказівник
  for (int x = -3; x < 4; x++) {		// цикл для змінної х від -3 до 4 з першим кроком 
    printf("x: %d\ty: %d\n", x, taskFunc(x));	// команда для виведення результатів 
  }
  return 0;
}
