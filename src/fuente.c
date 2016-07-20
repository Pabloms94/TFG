#include "fluence.h"
#include "cs.h"
#include "mu.h"
#include "structs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double fuente(double x, double u) {
	double r1, r2, r3, r4, r5, r6, res;

	r1 = fluence(x, u);
	r2 = cs(Ey, u);
	r3 = mu(Ey);
	r4 = (1/sin((M_PI/180)*Phi));
	r5 = (1/cos((M_PI/180)*Theta));
	r6= exp( r3 * r4 * r5 * x * (-1));
	res = r1* r2 * r6;

	return  res;
}

