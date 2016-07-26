#include <math.h>

double interpolar1DLogLog(double x, double X[], double Y[], int lit) {
	double r = 0, y1, y2;
	int i, j;

	for (i = 0; i < lit; i++) {
		if ((X[i] <= x) && (x <= X[i + 1]))
			break;
	}

	y1 = Y[i];
	y2 = Y[i + 1];

	r = exp(((log(x) - log(X[i])) / (log(X[i + 1]) - log(X[i]))) * (log(y2) - log(y1)) + log(y1));

	return r;
}
