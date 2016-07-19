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

	fgets(string1, 5000, f);
	fgets(string2, 5000, f);

	pch = strtok(string1, ",");
	while (pch != NULL) {
		columns++;
		myStruct->data[0][columns - 1] = atof(pch);
		pch = strtok(NULL, " ,");
	}

	columns = 0;
	pch = strtok(string2, ",");
	while (pch != NULL) {
		columns++;
		myStruct->data[1][columns - 1] = atof(pch);
		pch = strtok(NULL, " ,");
	}

	fclose(f);

	myStruct->col = columns;

	return columns;
}

