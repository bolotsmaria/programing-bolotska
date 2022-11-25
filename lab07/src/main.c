#include <stdio.h>
#include <math.h> // бібліотека, яка включає набір математичних функцій

int true=0, false=1;  
int isPrime(int x)  // функція, яка перевіряє чи х просте число 
{
  if (x>1)  // якщо n > 1
  {
    for (int i = 2; i < x; i++)       // у циклі перебираємо числа від 2 до n - 1
        if (x % i == 0)    // якщо n ділиться без остачі на i - повертаємо false (число не просте)
       return false;
       
        return true;             // якщо дійшло до даного оператора повертаємо true (число просте)
  }
  else{                               
    return false;           // інакше повертаємо false
    }
}
 int main()
 {
     int x;            // задаємо змінну х
     printf("введіть число:");              //  виведення запиту числа
     scanf("%d",&x);                        //  введення значення х
     printf("значення:%d\n",isPrime(x));    // виведення результату значення
 }







//#include <stdio.h>
//#include <string.h>
//int a(int total_words)
//{
  //total_words = 0; // Визначаємо лічильник total_words
  //char str[] = "The quick brown  fox jumps over   the lazy  dog"; // Визначаємо масив символів із цим значенням

  //int init_size = strlen(str);  // Визначаємо розмір масиву з довжиною масиву str

  //char delim[] = " ";  // Визначаємо яким символом будуть заповнені символами

  //char *ptr = strtok(str, delim);// Буферна змінна char ptr визначається як розділення масиву str на роздільник

  //while(ptr != NULL)   //Показник перебирає елементи поки не досягне 0

  //{
    //printf("'%s'\n", ptr); // Виводимо слово
       // total_words++; // Збільшуємо лічильник total_words
  //ptr = strtok(NULL, delim);    // Продовжуємо токенізацію існуючого рядка і повертаємо 0
  //}
    //printf("\n%d words.", total_words);// Виводимо рузультат
  //return 0;


//}
//int main()
//{
    //int total_words;
    //int c;
    //c = a(total_words);
  //return 0;
//}
