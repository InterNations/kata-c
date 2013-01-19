#include <stdlib.h>
#include <check.h>
#include "../src/library.h"

START_TEST(test_kata_add)
{
	fail_unless(kata_add(2, 2) == 4, "Addition not correctly");
}
END_TEST

Suite *kata_suite(void) {
	Suite *suite;
	TCase *test_case;

	suite = suite_create("kata");
	test_case = tcase_create("libkata");
	tcase_add_test(test_case, test_kata_add);
	suite_add_tcase(suite, test_case);

	return suite;
}

int main(void) {
	int number_failed;
	Suite *suite;
	SRunner *runner;

	suite = kata_suite();
	runner = srunner_create(suite);

	srunner_run_all(runner, CK_NORMAL);
	number_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
