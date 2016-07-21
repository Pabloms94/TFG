#include <stdio.h>
#include "interpolacionBidimensional.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

double cs(double eg, double u) {
	int mElectron = 511;

	double val = (u * E0 + mElectron) * 74;

	return val * val / (u * E0 * eg * (u * E0 + 2 * mElectron))
			* (interpolar2D(csS.grid[0], csS.grid[1], csS.data, csS.row,
					csS.col, u * E0, eg / (u * E0)));
}
