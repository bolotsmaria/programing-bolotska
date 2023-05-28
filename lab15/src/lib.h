//Індивідуальні завдання комплексної роботи №3.
/* Поля базового класу:
Чи акустичний інструмент (наприклад: так, ні)
Фірма/Майстер (https://consordini.com/best-violin-brands/) (наприклад: Stentor, Cecilio, Yamaha)
Рік створення (наприклад: 1970, 1850)
Смичок (структура, що містить вагу смичка у грамах та матеріал деревка, один з переліку: бразильське дерево, пернамбуку, скловолокно)
Розмір (https://kennedyviolins.com/pages/violin-size-chart) (один з переліку: 1, ½ , ¼, ¾ )
*/

/* Спадкоємець 1 - Скрипка. Додаткові поля:
Наявність містка (наприклад: так, ні)
Наявність підборідника (наприклад: так, ні)
Тип інструменту (один з переліку: сольний, оркестровий, універсальний)


#ifndef LIB_H
#define LIB_H

// Структура смичка
typedef struct {
    int weight;       // Вага смичка в грамах
    char material[20]; // Матеріал деревка смичка
} Bow;

// Структура смичкового інструменту
typedef struct {
    int isAcoustic;   // Чи акустичний інструмент (1 - так, 0 - ні)
    char brand[20];   // Фірма/Майстер
    int year;         // Рік створення
    Bow bow;          // Смичок
    int size;         // Розмір
} StringedInstrument;

#endif

*/

/* Спадкоємець 2 - Контрабас. Додаткові поля:
Наявність додаткової струни (наприклад: так, ні)
Довжина шпилю, см (https://en.wikipedia.org/wiki/Endpin) (наприклад: 45, 60)

#ifndef LIB_H
#define LIB_H

// Базовий клас - Смичковий інструмент
struct SmichkovyiInstrument {
    int rozmir;  // Розмір інструменту
};

// Скрипка - спадкоємець від Смичкового інструменту
struct Skripka {
    struct SmichkovyiInstrument instrument;  // Базовий інструмент
    int maystok;  // Наявність містка (0 - ні, 1 - так)
    int pidboridok;  // Наявність підборідка (0 - ні, 1 - так)
    char typ[20];  // Тип інструменту (сольний, оркестровий, універсальний)
};

#endif

*/

/* Методи для роботи з колекцією:
Знайти в колекції найстарішу скрипку фірми Yamaha
Обрати з колекції акустичні інструменти розміру ½
Відсортувати колекцію за вагою смичка від найважчого до найлегшого

#ifndef LIB_H
#define LIB_H

// Структура "базовий клас"
struct Instrument {
    char name[20];
    float price;
};

// Структура "Спадкоємець 2 - Контрабас"
struct Bass : public Instrument {
    char additionalString[4];
    float endpinLength;
};

#endif

*/

// Індивідуальні завдання. Обов'язкові завдання.
/* Розробити функцію, яка читає дані (масив елементів) з файлу.

#ifndef LIB_H
#define LIB_H

// Структура, що відображає базовий клас інструменту
struct Instrument {
    char manufacturer[50];
    int size;
    double bowWeight;
};

struct Instrument* findOldestYamahaViolin(struct Instrument* instruments, int numInstruments);
int selectHalfSizeAcousticInstruments(struct Instrument* instruments, int numInstruments, struct Instrument** selectedInstruments);
int compareInstrumentsByBowWeight(const void* a, const void* b);

#endif

*/

/* Розробити функцію, яка виводить масив елементів на екран.

#ifndef LIB_H
#define LIB_H

void print_array(int *array, int size);

#endif
*/

/* Реалізувати функцію №1 з категорії "Методи для роботи з колекцією", на вхід якої потрапляє масив об'єктів. Слід звернути увагу, що усі необхідні дані повинні бути передані як аргументи функції. Наприклад, якщо треба знайти всі машини марки "Форд", то функція потрібна мати аргумент "марка машини", та у main() викликати цю функцію з потрібним значенням марки.


#ifndef LIB_H
#define LIB_H

#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Car {
    char make[MAX_NAME_LEN];
    char model[MAX_NAME_LEN];
    int year;
} Car;

void find_cars_by_make(Car *cars, int size, char *make);

#endif
*/

/* Розробити функцію, яка буде сортувати масив елементів за заданим критерієм (полем).

#ifndef LIB_H
#define LIB_H

#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Car {
    char make[MAX_NAME_LEN];
    char model[MAX_NAME_LEN];
    int year;
} Car;

void sort_cars_by_year(Car *cars, int size);

#endif
*/

/* Розробити функцію, яка генерує елемент прикладної галузі згідно з індивідуальним завданням, при цьому:
- чисельні поля генеруються за допомогою функції rand() у діапазоні [N..N * 10], де N – номер варіанту;
- рядкові поля подані у вигляді конкатенації двох рядків:, напр., "Студент №" та унікального числа.

#ifndef LIB_H
#define LIB_H

#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generate_string(int n);
int generate_number(int n);
void generate_element(int n);

#endif
*/

//Додаткові завдання на розсуд викладача.
/* Виконати запис та читання масиву структур (з заздалегідь відомою кількістю елементів) у двох форматів: текстовому та бінарному. При бінарному методі зберігання структур виконати пошук та читання структури з файлу по індексу (за допомогою використання функції fseek).


#ifndef LIB_H
#define LIB_H

#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;


void write_to_text_file(Person *people, int num_people, char* filename);
void write_to_binary_file(Person *people, int num_people, char* filename);
void read_from_text_file(Person *people, int num_people, char* filename);
void read_from_binary_file(Person *people, int num_people, char* filename);
int search_in_binary_file(char* filename, int index);

#endif
*/












