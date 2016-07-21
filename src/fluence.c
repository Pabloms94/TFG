#include <stdio.h>
#include <stdlib.h>
#include "interpolacionBidimensional.h"
#include "structs.h"

double fluence(double x, double u) {
	return interpolar2D(fluenceS.grid[0], fluenceS.grid[1], fluenceS.data,
			fluenceS.row, fluenceS.col, x, u);
}
