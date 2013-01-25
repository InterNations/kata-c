#include <stdio.h>
#include "library.h"

#define BUZZ_SIZE 1024


void enum_func(const char *key, const char *value, const void *obj) {

	printf("%s\n", value);

}

int main(int argc, char *argv[]) {

	char buff[BUZZ_SIZE];

	StrMap *data = sm_new(1000);

	char *file = argv[1];
	printf("using %s\n", file);

    FILE *f = fopen(file, "r");
    while (feof(f) == 0) {
 	    fgets(buff, BUZZ_SIZE, f);

 	    size_t size = strlen(buff)+1;
 	    char *str = malloc(size-1);
 	    strncpy(str, buff, size-2);
 	    str[size-2] = '\0';

		kata_add_to_strmap(data, str);

	    free(str);
	}
    fclose(f);

    sm_enum(data, enum_func, NULL);

	sm_delete(data);

	return 0;
}
