#include "interpolacion.h"
#include "interpolar1DLogLog.h"
#include "csda.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

double mu(double energy) {
	return interpolar1DLogLog(energy, muS.data[0], muS.data[1], muS.col) * csda(E0);
}
