#include "interpolacion.h"
#include "csda.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

double mu(double energy) {
	double x[500], y[500], r1, r2;
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < muS.col; j++) {
			if (i == 0)
				x[j] = muS.data[i][j];
			if (i == 1)
				y[j] = muS.data[i][j];
		}

	r1 = lagrange(energy, x, y, muS.col);
	r2 = csda(E0);
	return r1 * r2;
}
