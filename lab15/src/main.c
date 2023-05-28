//Індивідуальні завдання комплексної роботи №3.
/*Поля базового класу:
Чи акустичний інструмент (наприклад: так, ні)
Фірма/Майстер (https://consordini.com/best-violin-brands/) (наприклад: Stentor, Cecilio, Yamaha)
Рік створення (наприклад: 1970, 1850)
Смичок (структура, що містить вагу смичка у грамах та матеріал деревка, один з переліку: бразильське дерево, пернамбуку, скловолокно)
Розмір (https://kennedyviolins.com/pages/violin-size-chart) (один з переліку: 1, ½ , ¼, ¾ )
*/

#include "lib.h"
#include <stdio.h>

int main() {
    // Створення масиву смичкових інструментів
    StringedInstrument instruments[3];

    // Заповнення першого інструменту
    instruments[0].isAcoustic = 1;
    strcpy(instruments[0].brand, "Stentor");
    instruments[0].year = 1970;
    instruments[0].bow.weight = 50;
    strcpy(instruments[0].bow.material, "бразильське дерево");
    instruments[0].size = 1;

    // Заповнення другого інструменту
    instruments[1].isAcoustic = 0;
    strcpy(instruments[1].brand, "Cecilio");
    instruments[1].year = 1850;
    instruments[1].bow.weight = 45;
    strcpy(instruments[1].bow.material, "пернамбуку");
    instruments[1].size = 3/4;

    // Заповнення третього інструменту
    instruments[2].isAcoustic = 1;
    strcpy(instruments[2].brand, "Yamaha");
    instruments[2].year = 2005;
    instruments[2].bow.weight = 55;
    strcpy(instruments[2].bow.material, "скловолокно");
    instruments[2].size = 1/2;

    // Доступ до елементів масиву за допомогою покажчиків
    StringedInstrument* ptr = instruments;

    printf("Перший інструмент:\n");
    printf("Чи акустичний: %s\n", ptr->isAcoustic ? "Так" : "Ні");
    printf("Фірма/Майстер: %s\n", ptr->brand);
    printf("Рік створення: %d\n", ptr->year);
    printf("Вага смичка: %d г\n", ptr->bow.weight);
    printf("Матеріал деревка смичка: %s\n", ptr->bow.material);
    printf("Розмір: %d\n", ptr->size);

    return 0;
}


/* Спадкоємець 1 - Скрипка. Додаткові поля:
Наявність містка (наприклад: так, ні)
Наявність підборідника (наприклад: так, ні)
Тип інструменту (один з переліку: сольний, оркестровий, універсальний)

#include "lib.h"
#include <stdio.h>

int main() {
    // Створення об'єкту скрипки
    struct Skripka skripka;
    
    // Заповнення полів об'єкту скрипки
    skripka.instrument.rozmir = 4;
    skripka.maystok = 1;
    skripka.pidboridok = 1;
    strcpy(skripka.typ, "сольний");
    
    // Доступ до елементів масиву через розіменування покажчиків
    struct Skripka *skripkaPtr = &skripka;
    
    printf("Розмір скрипки: %d\n", skripkaPtr->instrument.rozmir);
    printf("Наявність містка: %s\n", skripkaPtr->maystok ? "так" : "ні");
    printf("Наявність підборідка: %s\n", skripkaPtr->pidboridok ? "так" : "ні");
    printf("Тип інструменту: %s\n", skripkaPtr->typ);
    
    return 0;
}

*/

/* Спадкоємець 2 - Контрабас. Додаткові поля:
Наявність додаткової струни (наприклад: так, ні)
Довжина шпилю, см (https://en.wikipedia.org/wiki/Endpin) (наприклад: 45, 60)

...#include "lib.h"
#include <stdio.h>

int main() {
    // Створення об'єкту базового класу
    struct Instrument instrument;
    strcpy(instrument.name, "Смичковий інструмент");
    instrument.price = 1000.0;

    // Створення об'єкту класу "Спадкоємець 2 - Контрабас"
    struct Bass bass;
    strcpy(bass.name, "Спадкоємець 2 - Контрабас");
    bass.price = 2000.0;
    strcpy(bass.additionalString, "Так");
    bass.endpinLength = 45.0;

    // Доступ до елементів масиву через розіменування покажчиків
    struct Instrument *instruments[2];
    instruments[0] = &instrument;
    instruments[1] = (struct Instrument *)&bass;

// Виведення інформації про об'єкти
    printf("Базовий клас:\n");
    printf("Назва: %s\n", instruments[0]->name);
    printf("Ціна: %.2f\n", instruments[0]->price);

    printf("\nСпадкоємець 2 - Контрабас:\n");
    printf("Назва: %s\n", instruments[1]->name);
    printf("Ціна: %.2f\n", instruments[1]->price);
    printf("Наявність додаткової струни: %s\n", ((struct Bass *)instruments[1])->additionalString);
    printf("Довжина шпилю: %.2f см\n", ((struct Bass *)instruments[1])->endpinLength);

    return 0;
}

*/

/* Методи для роботи з колекцією:
Знайти в колекції найстарішу скрипку фірми Yamaha
Обрати з колекції акустичні інструменти розміру ½
Відсортувати колекцію за вагою смичка від найважчого до найлегшого


printf("Акустичні інструменти розміру ½:\n");
    for (int i = 0; i < numSelectedInstruments; i++) {
        printf("Розмір - %d, Вага смичка - %.2f\n", selectedInstruments[i]->size, selectedInstruments[i]->bowWeight);
    }

    // Сортування колекції за вагою смичка
    qsort(selectedInstruments, numSelectedInstruments, sizeof(struct Instrument*), compareInstrumentsByBowWeight);

    printf("Відсортована колекція за вагою смичка (від найважчого до найлегшого):\n");
    for (int i = 0; i < numSelectedInstruments; i++) {
        printf("Розмір - %d, Вага смичка - %.2f\n", selectedInstruments[i]->size, selectedInstruments[i]->bowWeight);
    }

    return 0;
}

*/

// Індивідуальні завдання. Обов'язкові завдання.
/* Розробити функцію, яка читає дані (масив елементів) з файлу.

#include "lib.h"
#include <stdio.h>

int main() {
    char filename[] = "data.txt";
    int array[100];
    int size = 100;
    read_array_from_file(filename, array, size);
    // тут можна продовжити роботу з масивом, який зчитали з файлу
    return 0;
}
*/

/* Розробити функцію, яка записує дані (масив елементів) у файл.

#include "lib.h"
#include <stdio.h>

int main() {
    char filename[] = "data.txt";
    int array[5] = {1, 2, 3, 4, 5};
    int size = 5;
    write_array_to_file(filename, array, size);
    return 0;
}
*/

/* Розробити функцію, яка виводить масив елементів на екран.

#include "lib.h"
#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int size = 5;
    print_array(array, size);
    return 0;
}
*/

/* Реалізувати функцію №1 з категорії "Методи для роботи з колекцією", на вхід якої потрапляє масив об'єктів. Слід звернути увагу, що усі необхідні дані повинні бути передані як аргументи функції. Наприклад, якщо треба знайти всі машини марки "Форд", то функція потрібна мати аргумент "марка машини", та у main() викликати цю функцію з потрібним значенням марки.

#include "lib.h"
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50

int main() {
    Car cars[] = {{"Ford", "Mustang", 2020},
                  {"Toyota", "Corolla", 2021},
                  {"Ford", "F-150", 2019}};
    int size = 3;
    char make[] = "Ford";
    find_cars_by_make(cars, size, make);
    return 0;
}
*/

/* Розробити функцію, яка буде сортувати масив елементів за заданим критерієм (полем).

#include "lib.h"
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50

int main() {
    Car cars[] = {{"Ford", "Mustang", 2020},
                  {"Toyota", "Corolla", 2021},
                  {"Ford", "F-150", 2019}};
    int size = 3;

    sort_cars_by_year(cars, size);

    int i;
    for (i = 0; i < size; i++) {
        printf("%s %s (%d)\n", (*(cars + i)).make, (*(cars + i)).model, (*(cars + i)).year);
    }

    return 0;
}
*/

/* Розробити функцію, яка генерує елемент прикладної галузі згідно з індивідуальним завданням, при цьому:
- чисельні поля генеруються за допомогою функції rand() у діапазоні [N..N * 10], де N – номер варіанту;
- рядкові поля подані у вигляді конкатенації двох рядків:, напр., "Студент №" та унікального числа.

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generate_string(int n) {
    char* prefix = "Студент №";
    char* number_str = malloc(10 * sizeof(char));
    sprintf(number_str, "%d", n);
    int prefix_len = strlen(prefix);
    int number_len = strlen(number_str);
    char* result = malloc((prefix_len + number_len + 1) * sizeof(char));
    strncpy(result, prefix, prefix_len);
    strncpy(result + prefix_len, number_str, number_len);
    result[prefix_len + number_len] = '\0';
    free(number_str);
    return result;
}

int generate_number(int n) {
    return n + (rand() % (n * 10 - n + 1));
}

void generate_element(int n) {
    char* str = generate_string(n);
    int num = generate_number(n);
    printf("Результат: %s %d\n", str, num);
    free(str);
}

int main() {
    srand(time(NULL)); // ініціалізуємо генератор випадкових чисел
    int variant = 15; // встановлюємо номер варіанту
    int n = 1;
    char* elements[1];
    elements[0] = (char*)malloc(sizeof(char) * 50);
    generate_element(variant);
    sprintf(elements[0], "%s %d", generate_string(variant), generate_number(variant));
    printf("Результат через розіменування покажчиків: %s\n", *elements);
    free(elements[0]);
    return 0;
}
*/

//Додаткові завдання на розсуд викладача.
/* Виконати запис та читання масиву структур (з заздалегідь відомою кількістю елементів) у двох форматів: текстовому та бінарному. При бінарному методі зберігання структур виконати пошук та читання структури з файлу по індексу (за допомогою використання функції fseek).

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

int main() {
    int num_people = 3;
    Person people[num_people];

    // Заповнити масив структур
    strcpy((people + 0)->name, "John");
    (people + 0)->age = 30;
    strcpy((people + 1)->name, "Mary");
    (people + 1)->age = 25;
    strcpy((people + 2)->name, "David");
    (people + 2)->age = 40;

    // Записати в текстовий файл
    write_to_text_file(people, num_people, "people.txt");

    // Записати в бінарний файл
    write_to_binary_file(people, num_people, "people.bin");

    // Зчитати з текстового файлу
    Person people_from_text[num_people];
    read_from_text_file(people_from_text, num_people, "people.txt");

    // Зчитати з бінарного файлу
    Person people_from_binary[num_people];
    read_from_binary_file(people_from_binary, num_people, "people.bin");

    // Вивести зчитані дані
    printf("People from text file:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s, %d\n", (people_from_text + i)->name, (people_from_text + i)->age);
    }

    return 0;
}
*/







