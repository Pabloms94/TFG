double lagrange(double x, double X[], double Y[], int lit){
	double r=0, num=1, den=1;
	int i, j;
	for(i=0; i<lit;i++){ //para el total de polinomios
		for(j=0; j<lit;j++){ //para cada polinomio
			if (i!=j){
				num*=(x - X[j]);
				den*=(X[i] - X[j] );
			}
		}
		num*=Y[i];
		r+=num/den;
		num=den=1;
	}
	return r;
}
