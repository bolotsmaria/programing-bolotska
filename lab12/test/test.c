#include <stdlib.h>
#include <check.h>
#include <stdio.h>

void pascal_triangle_iterative(int rows);

START_TEST(test_pascal_triangle)
{
    int rows = 5;

    // Expected output for 5 rows of Pascal's triangle
    char expected_output[] = "    1 \n   1 1 \n  1 2 1 \n 1 3 3 1 \n1 4 6 4 1 \n";

    // Redirect stdout to a buffer
    freopen("output.txt", "w", stdout);

    // Call the function
    pascal_triangle_iterative(rows);

    // Close stdout
    fclose(stdout);

    // Open the file and read the output
    FILE *fp;
    char output[100];
    fp = fopen("output.txt", "r");
    fgets(output, 100, fp);
    fclose(fp);

    // Compare the output to the expected output
    ck_assert_str_eq(output, expected_output);
}
END_TEST

int main(void)
{
    Suite *s = suite_create("Pascal's Triangle");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_pascal_triangle);

    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/*
Рекурсивний спосіб
#include <stdlib.h>
#include <check.h>
#include <stdio.h>

void pascal_triangle_recursive(int rows, int current_row);

START_TEST(test_pascal_triangle)
{
    int rows = 5;

    char expected_output[] = "    1 \n   1 1 \n  1 2 1 \n 1 3 3 1 \n1 4 6 4 1 \n";

    freopen("output.txt", "w", stdout);

    pascal_triangle_recursive(rows, 0);

    fclose(stdout);

    FILE *fp;
    char output[100];
    fp = fopen("output.txt", "r");
    fgets(output, 100, fp);
    fclose(fp);

    ck_assert_str_eq(output, expected_output);
}
END_TEST

void pascal_triangle_recursive(int rows, int current_row) {
  if (current_row > rows) {
    return;
  }

  int coef = 1;
  for (int j = 1; j <= rows - current_row; j++) {
    printf(" ");
  }

  for (int i = 0; i <= current_row; i++) {
    printf("%d ", coef);
    coef = coef * (current_row - i) / (i + 1);
  }
  printf("\n");

  pascal_triangle_recursive(rows, current_row + 1);
}

int main(void)
{
    Suite *s = suite_create("Pascal's Triangle");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_pascal_triangle);

    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
