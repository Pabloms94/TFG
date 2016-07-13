#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int lectura2D(char *path, Data2D *myStruct){
	char string1[5000];
	char string2[5000];
	char *pch, gridPath[100], add[100] = "grid.csv";
	int columns1 = 0, columns2 = 0, length, i= 0, j = 0;

	strcpy(gridPath, path);

	length = strlen(gridPath) - 1;
	for(i = length; i >= 0; i--){
		if(gridPath[i] == '/'){
			break;
		}
	}

	length = i+2+strlen(add);

	for(i = i+1;i<length;i++){
		gridPath[i] = add[j];
		j++;
	}

	FILE *f = fopen(gridPath, "r");

	fgets(string1, 500, f);
	fgets(string2, 500, f);

	pch = strtok(string1, ",");
	while (pch != NULL) {
		columns1++;
		myStruct->grid[0][columns1 - 1] = atof(pch);
		pch = strtok(NULL, " ,");
	}

	columns1 = 0;
	pch = strtok(string2, ",");
	while (pch != NULL) {
		columns1++;
		myStruct->grid[1][columns1 - 1] = atof(pch);
		pch = strtok(NULL, " ,");
	}

	fclose(f);

	f = fopen(path, "r");
	i = 0;
	while (feof(f) == 0){
		fgets (string1, 5000, f);
		j=0;
		pch = strtok(string1, ",");
		while (pch != NULL) {
			j++;
			myStruct->data[i][j - 1] = atof(pch);
			pch = strtok(NULL, " ,");
		}
		i++;
	}

	myStruct->col = j;
	myStruct->row = i;
	fclose(f);

	return columns1;

	/*if (columns1 <= columns2)
		return columns1;
	else return columns2;*/
}

