#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "lib.h"

double get_directory_size(const char *path);

START_TEST(test_get_directory_size)
{
    const char *test_dirname = "./testdir";
    system("mkdir -p ./testdir");
    FILE *fp = fopen("./testdir/testfile.txt", "w");
    fprintf(fp, "Test file content");
    fclose(fp);

    double expected_size = (double)strlen("Test file content");

    double actual_size = get_directory_size(test_dirname);

    ck_assert_double_eq(expected_size, actual_size);

    system("rm -rf ./testdir");

    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "Test result: %f\n", actual_size);
    fclose(fp);
}
END_TEST

int main(void)
{
    Suite *s = suite_create("DirectorySize");

    TCase *tc = tcase_create("Core");
    tcase_add_test(tc, test_get_directory_size);
    suite_add_tcase(s, tc);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
