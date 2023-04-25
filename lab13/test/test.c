#include "lib.h"
#include <stdlib.h>
#include <string.h>
#include <check.h>

START_TEST(test_count_digits)
{
    char text[] = "У 2021 році було зареєстровано понад 4 мільярди користувачів інтернету, що становить понад половину населення планети. Крім того, середня швидкість інтернет-з'єднання по світу цього року становила близько 32 Мбіт/с, що на 22% вище, ніж торік. Однак досі близько 3,5 мільярда людей не мають доступу до Інтернету, що є серйозною проблемою для розвитку глобальної економіки та соціальної сфери.";
    int expected_count = 5;
    int actual_count = count_digits(text, sizeof(text));
    ck_assert_int_eq(expected_count, actual_count);
}
END_TEST

int main(void)
{
    Suite *s = suite_create("Programming");
    TCase *tc_core = tcase_create("lab13");

    tcase_add_test(tc_core, test_count_digits);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}