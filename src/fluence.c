#include <stdio.h>
#include <stdlib.h>
#include "interpolacionBidimensional.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

double fluence(double x, double u) {
	double X[500], Y[500];
	double **Z;
	int i, j;

	for (i = 0; i < fluenceS.row; i++)
		X[i] = fluenceS.grid[0][i];
	for (i = 0; i < fluenceS.col; i++)
		Y[i] = fluenceS.grid[1][i];

	Z = (double **) malloc(fluenceS.row * (sizeof(double*)));

	for (i = 0; i < fluenceS.row; i++) {
		*(Z + i) = (double *) malloc(fluenceS.col * (sizeof(double)));
		if (*(Z + i) == NULL) {
			for (j = i - 1; j >= 0; j--)
				free(*(Z + j));
			free(Z);
		}
	}

	for (i = 0; i < fluenceS.row; i++) {
		for (j = 0; j < fluenceS.col; j++)
			Z[i][j] = fluenceS.data[i][j];
	}

	return interpolar2D(X, Y, Z, fluenceS.row, fluenceS.col, x, u);
}
