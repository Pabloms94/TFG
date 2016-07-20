#include "interpolacion.h"
#include "csda.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

double mu(double energy) {
	double r1, r2;

	r1 = lagrange(energy, muS.data[0], muS.data[1], muS.col);
	r2 = csda(E0);

	return r1 * r2;
}
