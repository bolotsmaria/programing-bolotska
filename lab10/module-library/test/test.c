#include "../src/lib.h"
#include <stdlib.h>
#include <check.h>

START_TEST(test_isPrime)
{
    #define DATA_SIZE_PRIME 10
    int input_data[] = { 1, 2, 3, 5, 7, 8, 9, 10, 20, 100 };
    int expected_values[] = { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
    for (int i = 0; i < DATA_SIZE_PRIME; i++) {
        int actual_value = isPrime(input_data[i]);
        ck_assert_int_eq(expected_values[i], actual_value);
    }
}
END_TEST

int main(void)
{
    Suite *s = suite_create("Programing");
    TCase *tc_core = tcase_create("lab09");

    tcase_add_test(tc_core, test_isPrime);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
