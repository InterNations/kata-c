#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include "../src/library.h"
#include "../src/strmap.h"

START_TEST(test_kata_sort_string)
{
	char *test1, *test2;

	/* TEST 1 */

	test1 = malloc(sizeof(char) * 8);

	strcpy(test1, "kinship");

	printf("%s", test1);

	kata_sort_string(test1);

	printf(" => %s\n", test1);

	fail_unless(strncmp(test1, "hiiknps", 7) == 0, "Sort not correctly");
	free(test1);

	/* TEST 2 */

	test2 = malloc(sizeof(char) * 5);

	strcpy(test2, "sort");

	printf("%s", test2);

	kata_sort_string(test2);

	printf(" => %s\n", test2);

	fail_unless(strncmp(test2, "orst", 4) == 0, "Sort not correctly");
	free(test2);



}
END_TEST

START_TEST(test_kata_anagrams)
{

	StrMap *data = sm_new(100);

	sm_put(data, "hiiknps", "kinship");

	fail_unless(sm_exists(data, "hiiknps") == 1, "Hash map works not");

	sm_delete(data);

}
END_TEST

START_TEST(test_kata_anagrams2)
{

	StrMap *data;
	char *test1, *test2, *outbuf;

	data = sm_new(100);

	test1 = malloc(sizeof(char) * 8);
	strcpy(test1, "kinship");

	kata_add_to_strmap(data, test1);

	fail_unless(sm_exists(data, "hiiknps") == 1, "Hash map works not");

	test2 = malloc(sizeof(char) * 8);
	strcpy(test2, "pinkish");

	kata_add_to_strmap(data, test2);


	outbuf = malloc(sizeof(char) * 20);
	sm_get(data, "hiiknps", outbuf, 20); 
	printf("output: %s\n", outbuf);

	fail_unless(strncmp(outbuf, "kinship pinkish", 15) == 0, "Hash map works not");


	sm_delete(data);

}
END_TEST

Suite *kata_suite(void) {
	Suite *suite;
	TCase *test_case;

	suite = suite_create("kata");
	test_case = tcase_create("libkata");
	tcase_add_test(test_case, test_kata_sort_string);
	tcase_add_test(test_case, test_kata_anagrams);
	tcase_add_test(test_case, test_kata_anagrams2);
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
