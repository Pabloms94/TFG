double interpolar1D(double x, double X[], double Y[], int lit) {
	double r = 0, y1, y2;
	int i, j;

	for (i = 0; i < lit; i++) {
		if ((X[i] <= x) && (x <= X[i + 1]))
			break;
	}

	y1 = Y[i];
	y2 = Y[i + 1];

	r = ((x - X[i]) / (X[i + 1] - X[i])) * (y2 - y1) + y1;

	return r;
}
