#include "interpolacion.h"
#include "csda.h"

struct Data1D {
	double data[2][500];
	int col;
};

double mu(double energy) {
	extern struct Data1D mu;
	double x[500], y[500];
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < mu.col; j++) {
			if (i == 0)
				x[j] = mu.data[i][j];
			if (i == 1)
				y[j] = mu.data[i][j];
		}

	return (lagrange(energy, x, y, mu.col) * csda(E0));
}
