#include "fluence.h"
#include "cs.h"
#include "mu.h"
#include "structs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double fuente(double x, double u) {
	double r1, r2, r3, r4, r5;

	r1 = mu(Ey);
	r2 = (1/sin(Phi));
	r3 = (1/sin(Theta));
	r4= exp( r1 * r2 * r3);


	return fluence(x, u) * cs(Ey, u) * r4;
}

