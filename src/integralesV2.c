/*
 ============================================================================
 Name        : integralesV2.c
 Author      : Pablo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float integral (float menor, float particiones, float dx);
float dobleIntegral (float menor1, float mayor2, float menor2, float particiones, float dx);
float funcion (float x, float y);

/**
 * Menor y mayor hacen referecia a los extremos de las integrales.
 * El uno indica que es de la integral externa, y el 2 de la interna.
 */

int main(void) {
	float menor1 = 1;
	float mayor1 = 2;
	float menor2 = 3;
	float mayor2 = 4;
	float particiones = 1000;
	float dy;
	float resultado;

	dy = (mayor1 - menor1) /particiones;
	resultado = dobleIntegral(menor1, mayor2, menor2, particiones, dy);
	printf ("RESULTADO : %f", resultado);

	return 0;
}
/*
float integral (float menor, float particiones, float dx){
	int i;
	float verticeMenor;
	float valorFuncion;
	float area;
	float resultado = 0;

	for(i = 0; i < particiones; i++){
		verticeMenor = menor + i*dx;
		valorFuncion = funcion(verticeMenor);
		area = valorFuncion * dx;
		resultado += area;
	}

	return resultado;
}*/
/**
 * Los valores verticeMenor hacen referencia al valor del extremo inferior de la partición que se toma como referencia.
 */
float dobleIntegral (float menor1, float mayor2, float menor2, float particiones, float dy){
	int i, j;
	float verticeMenorY, verticeMenorX;
	float valorFuncion;
	float area1, area2;
	float resultado2, resultado1 = 0;
	float dx;

	for(i = 0; i < particiones; i++){

		verticeMenorY = menor1 + i * dy;
		dx = (mayor2 - menor2) / particiones;
		resultado2 = 0;

		for (j = 0; j < particiones; j++) {
			verticeMenorX = menor2 + dx * j;
			valorFuncion = funcion(verticeMenorY,verticeMenorX);
			area2 = valorFuncion * dx;
			resultado2 += area2;
		}

		area1 = resultado2 * dy;
		resultado1 += area1;
	}

	return resultado1;
}

float funcion (float x, float y){
	return x*y;
}
