#include "interpolacion.h"
#include "structs.h"

double csda(double energy) {
	return interpolar1D(energy, csdaS.data[0], csdaS.data[1], csdaS.col);
}

