#include <stdio.h>
#include <check.h>
#include "maxSubArray.h"

START_TEST(test_maxSubArray)
{
    int input_data[][10] = {
        {-2, -3, 4, -1, -2, 1, 5, -3},
        {5, -2, 3, -1, 2},
        {-1, -2, -3},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {-5, -4, -3, -2, -1},
        {1, 2, -1, 4, -5, 6, 7},
        {1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 3, 4, -1, -2, -3, -4, 5, 6},
    };

    int input_data_size[] = {8, 5, 3, 10, 5, 7, 1, 10, 10, 10};

    int expected_values[][2] = {
        {7, 6},
        {8, 2},
        {0, 0},
        {0, 9},
        {0, 0},
        {0, 6},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 9},
    };

    int expected_sums[] = {7, 9, -1, 55, -1, 19, 1, 0, -1, 15};

    for (int i = 0; i < 10; i++) {
        int start = 0, end = 0;
        int actual_sum = maxSubArray(input_data[i], input_data_size[i], &start, &end);
        ck_assert_int_eq(expected_sums[i], actual_sum);
        ck_assert_int_eq(expected_values[i][0], start);
        ck_assert_int_eq(expected_values[i][1], end);
    }
}
END_TEST

int main(void)
{
    Suite *s = suite_create("Programming");
    TCase *tc_core = tcase_create("Lab11");

    tcase_add_test(tc_core, test_maxSubArray);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}