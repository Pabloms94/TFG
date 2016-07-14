#include <stdio.h>
#include "interpolacionBidimensional.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

double cs(double eg, double u) {
	double X[500], Y[500];
	double **Z;
	int i, j;
	int mElectron = 511;

	double val = (u * E0 + mElectron) * 74;

	for (i = 0; i < csS.row; i++)
		X[i] = csS.grid[0][i];
	for (i = 0; i < csS.col; i++)
		Y[i] = csS.grid[1][i];

	Z = (double **) malloc(csS.row * (sizeof(double*)));

	for (i = 0; i < csS.row; i++) {
		*(Z + i) = (double *) malloc(csS.col * (sizeof(double)));
		if (*(Z + i) == NULL) {
			for (j = i - 1; j >= 0; j--)
				free(*(Z + j));
			free(Z);
		}
	}

	for (i = 0; i < csS.row; i++) {
		for (j = 0; j < csS.col; j++)
			Z[i][j] = csS.data[i][j];
	}

	return val * val / (u * E0 * eg * (u * E0 + 2 * mElectron))
			* (interpolar2D(X, Y, Z, csS.row, csS.col, u * E0,
					eg / (u * E0)));
}
