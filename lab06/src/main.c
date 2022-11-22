#include <stdio.h>								
#include <string.h>								//бібліотека яка визначає один тип змінної і різні функції для роботи з масивами символ
int main()
{
	int total_words = 0;							//визначаємо личільник total_words							
		char str[] = "The quick brown  fox jumps over  the lazy dog";	//визначаємо масив символів із цим значенням 
       int init_size = strlen(str);						//визначаємо розмір масиву з довжиною масиву str
char delim[] = " ";								//визначаємо яким символом будуть заповнені символами
 char *ptr = strtok(str, delim);						//буферна змінна char ptr визначається як розділення масиву str на роздільник  
while(ptr != NULL)								//показник перебирає елементи поки не досягне 0
{
printf("'%s'\n", ptr);								//виводмо слово
total_words++;									//збільшуємо лічильник total_words
	ptr = strtok(NULL,delim);						//продовжуємо токенізацію існуючого рядка і повертаємо 0
}
printf("\n%d words.", total_words);						//виводимо результат 
return 0;
}


