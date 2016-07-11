#include "interpolacion.h"
#include "csda.h"
#include "structs.h"

double mu(double energy) {
	extern struct Data1D muS;
	extern double E0;
	double x[500], y[500];
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < muS.col; j++) {
			if (i == 0)
				x[j] = muS.data[i][j];
			if (i == 1)
				y[j] = muS.data[i][j];
		}

	return (lagrange(energy, x, y, muS.col) * csda(E0));
}
