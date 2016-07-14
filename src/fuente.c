#include "fluence.h"
#include "cs.h"
#include "mu.h"
#include "structs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double fuente(double x, double u) {

	printf("\n\nFUENTE x = %lf, u = %lf\n\n");

	return (fluence(x, u) * cs(Ey, u) * exp(mu(Ey) * (1/sin(Phi)) * (1/sin(Theta))));
}

