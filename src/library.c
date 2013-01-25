#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/strmap.h"

int kata_add(int left, int right) {
	return left + right;
}

int compare (const void * a, const void * b)
{
//	printf("COMPARE");
  return strcmp(a, b);
}

void kata_sort_string(char *input) {

/*	char *input2 = malloc(strlen(input)+1);
	strcpy(input2, input);
*/
	qsort(input, strlen(input), 1, compare);

/*	strcpy(input, input2);

	free(input2);
*/
}

void kata_add_to_strmap(StrMap *map, char *input) {

	char *orig = malloc(strlen(input)+1);
	strcpy(orig, input);

	kata_sort_string(input);

	if (sm_exists(map, input) == 1) {

		int bufsize = sm_get(map, input, NULL, 0);

		char *val = malloc(bufsize + 1 + strlen(orig) + 1);
		sm_get(map, input, val, bufsize);
		strcat(val, " ");
		strcat(val, orig);
		sm_put(map, input, val);
	//	printf("%s => %s\n", input, val);

		free(val);
	}
	else {
		sm_put(map, input, orig);
	//printf("%s => %s\n", input, orig);
	}

	free(orig);

}