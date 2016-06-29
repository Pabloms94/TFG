#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lectura1D(char *path, int row, int col, double mat[row][col]) {
	char string1[500];
	char string2[500];
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
		printf("The token %d is:  %s\n",columns, pch);
		mat[0][columns - 1] = atof(pch);
		pch = strtok(NULL, " ,");
	}

	columns = 0;
	pch = strtok(string2, ",");
	while (pch != NULL) {
		columns++;
		printf("The token2 %d is:  %s\n", columns, pch);
		mat[1][columns - 1] = atof(pch);
		pch = strtok(NULL, " ,");
	}

	fclose(f);

	return columns;
}

