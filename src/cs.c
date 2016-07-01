#include <stdio.h>
#include "interpolacionBidimensional.h"

struct Data2D{
	double grid[2][500];
	double data[500][500];
	int row, col;
};

double cs(double eg, double u) {
	extern struct Data2D fluence;
	double X[500], Y[500];
	double **Z;
	int i, j;
	int mElectron = 511;

	double val = (u * E0 + mElectron) * 74;

	for (i = 0; i < fluence.row; i++)
		X[i] = fluence.grid[0][i];
	for (i = 0; i < fluence.col; i++)
		Y[i] = fluence.grid[1][i];

	Z = (double **) malloc(fluence.row * (sizeof(double*)));

	for (i = 0; i < fluence.row; i++) {
		*(Z + i) = (double *) malloc(fluence.col * (sizeof(double)));
		if (*(Z + i) == NULL) {
			for (j = i - 1; j >= 0; j--)
				free(*(Z + j));
			free(Z);
		}
	}

	for (i = 0; i < fluence.row; i++) {
		for (j = 0; j < fluence.col; j++)
			Z[i][j] = fluence.data[i][j];
	}

	return val * val / (u * E0 * eg * (u * E0 + 2 * mElectron))
			* (interpolar2D(X, Y, Z, fluence.row, fluence.col, u * E0,
					eg / (u * E0)));
}
