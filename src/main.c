#include <stdio.h>
#include "library.h"

#define BUZZ_SIZE 1024


int main(int argc, char *argv[]) {

	char buff[BUZZ_SIZE];

	StrMap *data = sm_new(1000);

	char *file = argv[1];
	printf("using %s\n", file);

    FILE *f = fopen(file, "r");
    while (feof(f) == 0) {
    	size_t size;
    	char *str;

 	    fgets(buff, BUZZ_SIZE, f);

 	    size = strlen(buff)+1;
 	    str = malloc(size-1);
 	    strncpy(str, buff, size-2);
 	    str[size-2] = '\0';

		kata_add_to_strmap(data, str);

	    free(str);
	}
    fclose(f);

    sm_enum(data, kata_print_result, NULL);

	sm_delete(data);

	return 0;
}
