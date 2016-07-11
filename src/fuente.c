#include "fluence.h"
#include "cs.h"
#include "mu.h"
#include "structs.h"
#include <math.h>

double fuente(double x, double u) {

	return fluence(x, u) * cs(Ey, u) * exp(mu(Ey) * (1/sin(Phi)) * (1/sin(Theta)));
}

