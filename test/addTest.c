#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"

#include "../src/fuente.h"
#include "../src/integrales.h"
#include "../src/interpolacion.h"
#include "../src/interpolacionBidimensional.h"
#include "../src/interpolar1DLogLog.h"

#define eps 0.01

/*void TestIntegralBasica(CuTest* tc) {
	double menor1 = 1;
	double mayor1 = 2;
	double menor2 = 3;
	double mayor2 = 4;
	double resultado;


	resultado = dobleIntegral(fuente, mayor1, menor1, mayor2, menor2);

	CuAssertDblEquals(tc, 5.25, resultado, eps);
}*/

void TestInterpolacion1(CuTest* tc) {
	double energia[60];
	double atenuacion[60];
	double absorcion[60];
	int i = 0;
	double energiaInterpolar = 1;
	double interpolacion;
	double x1a[10], x2a[10];

	/*FILE* f = fopen("data/mu/mu74.csv", "r");

	while (fscanf(f, "%lg,%lg,%lg\n", &energia[i], &atenuacion[i],
			&absorcion[i]) != EOF) {
		//printf("Lectura: a=%lf, b=%lf,c=%lf\n",energia[i],atenuacion[i],absorcion[i]);

		i++;
	}
	fclose(f);

	interpolacion = interpolar1D(energiaInterpolar, energia, atenuacion, i);
	CuAssertDblEquals(tc, 3683.0, interpolacion, eps);

	energiaInterpolar = 5;
	interpolacion = interpolar1D(energiaInterpolar, energia, atenuacion, i);
	CuAssertDblEquals(tc, 553.4, interpolacion, eps);

	energiaInterpolar = 20;
	interpolacion = interpolar1D(energiaInterpolar, energia, atenuacion, i);
	CuAssertDblEquals(tc, 65.73, interpolacion, eps);

	energiaInterpolar = 1500;
	interpolacion = interpolar1D(energiaInterpolar, energia, atenuacion, i);
	CuAssertDblEquals(tc, 0.05, interpolacion, eps);*/

	for (i = 0; i < 10; i++) {
		x1a[i] = i;
		x2a[i] = i;
	}

	energiaInterpolar = 0;
	for (i= 0; i<10; i++){
		interpolacion = interpolar1D(energiaInterpolar, x1a, x2a, 10);
		CuAssertDblEquals(tc, 3, interpolacion, eps);
		energiaInterpolar += 0.5;
	}

	energiaInterpolar = 3;
			for (i= 0; i<10; i++){
				interpolacion = interpolar1DLogLog(energiaInterpolar, x1a, x2a, 10);
				CuAssertDblEquals(tc, energiaInterpolar, interpolacion, eps);
				energiaInterpolar += 0.5;
			}
}

void TestInterpolacion2D1(CuTest* tc) {
	double x1a[10], x2a[10], **y, resultado;
	int i, j, k, l;

	y = (double **) malloc(10 * (sizeof(double*)));

	for (i = 0; i < 10; i++) {
		*(y + i) = (double *) malloc(10 * (sizeof(double)));
		if (*(y + i) == NULL) {
			for (j = i - 1; j >= 0; j--)
				free(*(y + j));
			free(y);
		}
	}

	for (i = 0; i < 10; i++) {
		x1a[i] = i;
		x2a[i] = i;
		for (j = 0; j < 10; j++)
			y[i][j] = j;
	}

	resultado = interpolar2D(x1a, x2a, y, 10, 10, 2.5, 7.5);

	CuAssertDblEquals(tc, 7.5, resultado, eps);

	for (i = 0; i < 10; i++)
		free(y[i]);
	free(y);

}

CuSuite* AddGetSuite(void) {
	CuSuite* suite = CuSuiteNew();

	//SUITE_ADD_TEST(suite, TestIntegralBasica);

	SUITE_ADD_TEST(suite, TestInterpolacion1);
	SUITE_ADD_TEST(suite, TestInterpolacion2D1);

	return suite;
}
