//Індивідуальні завдання комплексної роботи №3.
/* Методи для роботи з колекцією:
Знайти в колекції найстарішу скрипку фірми Yamaha
Обрати з колекції акустичні інструменти розміру ½
Відсортувати колекцію за вагою смичка від найважчого до найлегшого

#include "lib.h"
#include <stdio.h>

// Функція для знаходження найстарішої скрипки фірми Yamaha
struct Instrument* findOldestYamahaViolin(struct Instrument* instruments, int numInstruments) {
    struct Instrument* oldestViolin = NULL;
    int oldestYear = 0;

    for (int i = 0; i < numInstruments; i++) {
        if (strcmp(instruments[i].manufacturer, "Yamaha") == 0) {
            if (oldestViolin == NULL || instruments[i].size < oldestYear) {
                oldestViolin = &instruments[i];
                oldestYear = instruments[i].size;
            }
        }
    }

    return oldestViolin;
}

// Функція для вибору акустичних інструментів розміру ½
int selectHalfSizeAcousticInstruments(struct Instrument* instruments, int numInstruments, struct Instrument** selectedInstruments) {
    int count = 0;

    for (int i = 0; i < numInstruments; i++) {
        if (instruments[i].size == 1 && strcmp(instruments[i].manufacturer, "Acoustic") == 0) {
            selectedInstruments[count] = &instruments[i];
            count++;
        }
    }

    return count;
}

// Функція для порівняння інструментів за вагою смичка
int compareInstrumentsByBowWeight(const void* a, const void* b) {
    struct Instrument* instrumentA = *(struct Instrument**)a;
    struct Instrument* instrumentB = *(struct Instrument**)b;

    if (instrumentA->bowWeight < instrumentB->bowWeight) {
        return 1;  // Вага смичка в instrumentA більша, тому instrumentA йде після instrumentB
    } else if (instrumentA->bowWeight > instrumentB->bowWeight) {
        return -1; // Вага смичка в instrumentA менша, тому instrumentA йде перед instrumentB
    } else {
        return 0;  // Ваги смичків однакові
    }
}

*/




