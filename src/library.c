#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "strmap.h"

int compare (const void * a, const void * b)
{
   return strcmp(a, b);
}

void kata_sort_string(char *input) {
	qsort(input, strlen(input), 1, compare);
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

		free(val);
	}
	else {
		sm_put(map, input, orig);
	}

	free(orig);

}

void kata_print_result(const char *key, const char *value, const void *obj) {

	if (strchr(value, ' ') != NULL) {
		printf("%s\n", value);
	}
}
