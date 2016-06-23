double interpolar2D(double* x1a, double* x2a, double** y, int n1, int n2, double x1, double x2){
	int i, j;
	double y1, y2, y3, y4, t, u, resultado;

	for(i = 0; i < n1; i++){
		if((x1a[i] <= x1) && (x1 <= x1a[i + 1]))
			break;
	}

	for(j = 0; j < n2; j++){
		if((x2a[j] <= x2) && (x2 <= x2a[j + 1]))
			break;
	}

	y1 = y[i][j];
	y2 = y[i+1][j];
	y3 = y[i+1][j+1];
	y4 = y[i][j+1];

	t = (x1 - x1a[i]) / (x1a[i+1] - x1a[i]);
	u = (x2 - x2a[j]) / (x2a[j+1] - x2a[j]);

	resultado = (1-t) * (1-u) * y1 + t *(1-u) * y2 + t * u * y3 + (1-t) * u * y4;

}
