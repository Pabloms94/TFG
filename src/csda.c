#include "interpolacion.h"
#include "structs.h"

double csda(double energy) {
	extern struct Data1D csdaS;
	double x[500], y[500];
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < csdaS.col; j++) {
			if (i == 0)
				x[j] = csdaS.data[i][j];
			if (i == 1)
				y[j] = csdaS.data[i][j];
		}

	return lagrange(energy, x, y, csdaS.col);
}

