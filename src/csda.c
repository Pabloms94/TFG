#include "interpolacion.h"
#include "structs.h"

double csda(double energy) {
	return lagrange(energy, csdaS.data[0], csdaS.data[1], csdaS.col);
}

