#include "interpolacion.h"

struct Data1D {
	double data[2][500];
	int col;
};

double csda(double energy) {
	extern struct Data1D csda;
	double x[500], y[500];
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < csda.col; j++) {
			if (i == 0)
				x[j] = csda.data[i][j];
			if (i == 1)
				y[j] = csda.data[i][j];
		}

	return lagrange(energy, x, y, csda.col);
}

