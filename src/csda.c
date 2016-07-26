#include "interpolacion.h"
#include "interpolar1DLogLog.h"
#include "structs.h"

double csda(double energy) {
	return interpolar1DLogLog(energy, csdaS.data[0], csdaS.data[1], csdaS.col);
}

