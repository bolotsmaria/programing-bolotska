#include "lib.h"
#include <check.h>

START_TEST(test_findOldestYamahaViolin)
{
    struct Instrument instruments[5];

    strcpy(instruments[0].manufacturer, "Yamaha");
    instruments[0].size = 1;
    instruments[0].bowWeight = 1.2;

    strcpy(instruments[1].manufacturer, "Acoustic");
    instruments[1].size = 1;
    instruments[1].bowWeight = 0.8;

    strcpy(instruments[2].manufacturer, "Yamaha");
    instruments[2].size = 2;
    instruments[2].bowWeight = 1.5;

    strcpy(instruments[3].manufacturer, "Acoustic");
    instruments[3].size = 1;
    instruments[3].bowWeight = 0.7;

    strcpy(instruments[4].manufacturer, "Yamaha");
    instruments[4].size = 3;
    instruments[4].bowWeight = 1.0;

    struct Instrument* oldestYamahaViolin = findOldestYamahaViolin(instruments, 5);
    ck_assert_int_eq(oldestYamahaViolin->size, 1);
    ck_assert_double_eq(oldestYamahaViolin->bowWeight, 1.2);
}

START_TEST(test_selectHalfSizeAcousticInstruments)
{
    struct Instrument instruments[5];

    strcpy(instruments[0].manufacturer, "Yamaha");
    instruments[0].size = 1;
    instruments[0].bowWeight = 1.2;

    strcpy(instruments[1].manufacturer, "Acoustic");
    instruments[1].size = 1;
    instruments[1].bowWeight = 0.8;

    strcpy(instruments[2].manufacturer, "Yamaha");
    instruments[2].size = 2;
    instruments[2].bowWeight = 1.5;

    strcpy(instruments[3].manufacturer, "Acoustic");
    instruments[3].size = 1;
    instruments[3].bowWeight = 0.7;

    strcpy(instruments[4].manufacturer, "Yamaha");
    instruments[4].size = 3;
    instruments[4].bowWeight = 1.0;

    struct Instrument* selectedInstruments[5];
    int numSelectedInstruments = selectHalfSizeAcousticInstruments(instruments, 5, selectedInstruments);

    ck_assert_int_eq(numSelectedInstruments, 1);
    ck_assert_int_eq(selectedInstruments[0]->size, 1);
    ck_assert_double_eq(selectedInstruments[0]->bowWeight, 0.8);
}

START_TEST(test_compareInstrumentsByBowWeight)
{
    struct Instrument instrument1;
    struct Instrument instrument2;
    struct Instrument instrument3;

    instrument1.bowWeight = 1.2;
    instrument2.bowWeight = 0.8;
    instrument3.bowWeight = 1.5;

    ck_assert_int_eq(compareInstrumentsByBowWeight(&instrument1, &instrument2), -1);
    ck_assert_int_eq(compareInstrumentsByBowWeight(&instrument2, &instrument1), 1);
    ck_assert_int_eq(compareInstrumentsByBowWeight(&instrument1, &instrument3), 0);
}

Suite* test_suite()
{
    Suite* s = suite_create("Programing");
    TCase* tc_core = tcase_create("lab15");

    tcase_add_test(tc_core, test_findOldestYamahaViolin);
    tcase_add_test(tc_core, test_selectHalfSizeAcousticInstruments);
    tcase_add_test(tc_core, test_compareInstrumentsByBowWeight);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    Suite* s = test_suite();
    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

