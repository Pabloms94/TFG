#include <stdio.h>

#include "CuTest.h"

#include "../src/integrales.h"
#include "../src/interpolacion.h"

#define eps 0.01

void TestIntegralBasica (CuTest* tc){
	double menor1 = 1;
	double mayor1 = 2;
	double menor2 = 3;
	double mayor2 = 4;
	int particiones = 1000;
	double resultado;

	resultado = dobleIntegral(mayor1, menor1, mayor2, menor2, particiones);

	CuAssertDblEquals(tc, 5.25, resultado, eps);
}


void TestInterpolacion1 (CuTest* tc){
	double energia[60];
	double atenuacion[60];
	double absorcion[60];
	int i = 0;
	double energiaInterpolar = 1;
	double interpolacion;

	FILE* f= fopen("../mu/mu74.csv","r");

	while (fscanf(f,"%lg,%lg,%lg\n",&energia[i],&atenuacion[i],&absorcion[i])!=EOF){
			//printf("Lectura: a=%lf, b=%lf,c=%lf\n",energia[i],atenuacion[i],absorcion[i]);
			i++;
	}
	fclose(f);

	interpolacion = lagrange (energiaInterpolar, energia, atenuacion, i);

	CuAssertDblEquals(tc, 3683.0, interpolacion, eps);

}

void TestInterpolacion2 (CuTest* tc){
	double energia[60];
	double atenuacion[60];
	double absorcion[60];
	int i = 0;
	double energiaInterpolar = 5;
	double interpolacion;

	FILE* f= fopen("../mu/mu74.csv","r");

	while (fscanf(f,"%lg,%lg,%lg\n",&energia[i],&atenuacion[i],&absorcion[i])!=EOF){
			//printf("Lectura: a=%lf, b=%lf,c=%lf\n",energia[i],atenuacion[i],absorcion[i]);
			i++;
	}
	fclose(f);

	interpolacion = lagrange (energiaInterpolar, energia, atenuacion, i);

	CuAssertDblEquals(tc, 553.4, interpolacion, eps);

}

void TestInterpolacion3 (CuTest* tc){
	double energia[60];
	double atenuacion[60];
	double absorcion[60];
	int i = 0;
	double energiaInterpolar = 20;
	double interpolacion;

	FILE* f= fopen("../mu/mu74.csv","r");

	while (fscanf(f,"%lg,%lg,%lg\n",&energia[i],&atenuacion[i],&absorcion[i])!=EOF){
			//printf("Lectura: a=%lf, b=%lf,c=%lf\n",energia[i],atenuacion[i],absorcion[i]);
			i++;
	}
	fclose(f);

	interpolacion = lagrange (energiaInterpolar, energia, atenuacion, i);

	CuAssertDblEquals(tc, 65.73, interpolacion, eps);

}

void TestInterpolacion4 (CuTest* tc){
	double energia[60];
	double atenuacion[60];
	double absorcion[60];
	int i = 0;
	double energiaInterpolar = 1500;
	double interpolacion;

	FILE* f= fopen("../mu/mu74.csv","r");

	while (fscanf(f,"%lg,%lg,%lg\n",&energia[i],&atenuacion[i],&absorcion[i])!=EOF){
			//printf("Lectura: a=%lf, b=%lf,c=%lf\n",energia[i],atenuacion[i],absorcion[i]);
			i++;
	}
	fclose(f);

	interpolacion = lagrange (energiaInterpolar, energia, atenuacion, i);

	CuAssertDblEquals(tc, 0.05, interpolacion, eps);

}
CuSuite* AddGetSuite(void){
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestIntegralBasica);
	SUITE_ADD_TEST(suite, TestInterpolacion1);
	SUITE_ADD_TEST(suite, TestInterpolacion2);
	SUITE_ADD_TEST(suite, TestInterpolacion3);
	SUITE_ADD_TEST(suite, TestInterpolacion4);

	return suite;
}
