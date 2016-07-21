#include "fluence.h"
#include "cs.h"
#include "mu.h"
#include "structs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double fuente(double x, double u) {
	double r1, r2, r3, r4, r5, r6, res;

	return fluence(x, u) * cs(Ey, u)
			* exp(
					mu(Ey) * (1 / sin((M_PI / 180) * Phi))
							* (1 / cos((M_PI / 180) * Theta)) * x * (-1));
}

