#include <stdio.h>
#include <stdlib.h>

double dobleIntegral(double (*f)(double, double), double mayor1, double menor1,
		double mayor2, double menor2) {
	int i, j;
	int particiones = 2;
	double verticeMenorY, verticeMenorX;
	double valorFuncion;
	double area1, area2;
	double resultado2, resultado1 = 0;
	double dx, dy;

	dy = (mayor1 - menor1) / particiones;

	for (i = 0; i < particiones; i++) {

		verticeMenorY = menor1 + i * dy;
		dx = (mayor2 - menor2) / particiones;
		resultado2 = 0;

		for (j = 0; j < particiones; j++) {
			verticeMenorX = menor2 + dx * j;
			valorFuncion = (*f)(verticeMenorY, verticeMenorX);
			area2 = valorFuncion * dx;
			resultado2 += area2;
		}

		area1 = resultado2 * dy;
		resultado1 += area1;

	}
	return resultado1;
}
