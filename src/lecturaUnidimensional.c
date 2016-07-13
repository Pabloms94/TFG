#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

int lectura1D(char *path, Data1D *myStruct) {
	char string1[5000];
	char string2[5000];
	char *pch;
	int columns = 0;

	FILE *f = fopen(path, "r");

	fgets(string1, 500, f);
	fgets(string2, 500, f);

	printf("%s\n", string1);
	printf("%s\n", string2);

	pch = strtok(string1, ",");
	while (pch != NULL) {
		columns++;
		//printf("The token %d is:  %s\n",columns, pch);
		myStruct->data[0][columns - 1] = atof(pch);
		pch = strtok(NULL, " ,");
	}

	columns = 0;
	pch = strtok(string2, ",");
	while (pch != NULL) {
		columns++;
		//printf("The token2 %d is:  %s\n", columns, pch);
		myStruct->data[1][columns - 1] = atof(pch);
		pch = strtok(NULL, " ,");
	}

	fclose(f);

	return columns;
}

