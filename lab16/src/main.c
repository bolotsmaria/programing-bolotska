#include "list.h"

int main() {
    List* instrument_list = create_list();

    // Додавання об'єктів до списку
    Entity* entity1 = create_entity(1, "Stentor", 1970, 20.5, "бразильське дерево", 1);
    Entity* entity2 = create_entity(1, "Cecilio", 1850, 18.2, "пернамбуку", 1);
    Entity* entity3 = create_entity(0, "Yamaha", 1995, 22.8, "скловолокно", 1);

    add_entity(instrument_list, entity1);
    add_entity(instrument_list, entity2);
    add_entity(instrument_list, entity3);

    // Виведення вмісту списку на екран
    printf("Instrument List:\n");
    print_list(instrument_list);
    printf("\n");

    // Видалення об'єкту зі списку за індексом
    remove_entity(instrument_list, 1);

    // Сортування вмісту списку за вагою смичка
    sort_by_bow_weight(instrument_list);

    // Виведення вмісту списку на екран після видалення та сортування
    printf("Instrument List after removal and sorting:\n");
    print_list(instrument_list);

    // Звільнення пам'яті
    destroy_list(instrument_list);

    return 0;
}
