#include "list.h"
#include <check.h>

START_TEST(test_list_operations)
{
    // Створення списку
    List* instrument_list = create_list();

    // Додавання об'єктів до списку
    Entity* entity1 = create_entity(1, "Stentor", 1970, 20.5, "бразильське дерево", 1);
    Entity* entity2 = create_entity(1, "Cecilio", 1850, 18.2, "пернамбуку", 1);
    Entity* entity3 = create_entity(0, "Yamaha", 1995, 22.8, "скловолокно", 1);

    add_entity(instrument_list, entity1);
    add_entity(instrument_list, entity2);
    add_entity(instrument_list, entity3);

    // Перевірка кількості елементів у списку
    ck_assert_int_eq(3, list_length(instrument_list));

    // Видалення об'єкту зі списку за індексом
    remove_entity(instrument_list, 1);

    // Перевірка кількості елементів у списку після видалення
    ck_assert_int_eq(2, list_length(instrument_list));

    // Сортування вмісту списку за вагою смичка
    sort_by_bow_weight(instrument_list);

    // Перевірка впорядкованості списку за вагою смичка
    Node* current = instrument_list->head;
    ck_assert(current->entity->bow.weight >= current->next->entity->bow.weight);

    // Звільнення пам'яті
    destroy_list(instrument_list);
}
END_TEST

Suite* list_suite(void)
{
    Suite* suite = suite_create("List");
    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_list_operations);
    suite_add_tcase(suite, tc_core);
    return suite;
}

int main(void)
{
    Suite* suite = list_suite();
    SRunner* runner = srunner_create(suite);
    srunner_run_all(runner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}