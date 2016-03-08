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
float funcion (float x);

int main(void) {
	float menor = 4;
	float mayor = 7;
	float particiones = 1000;
	float dx;
	float resultado;

	dx = (mayor - menor) /particiones;
	resultado = integral(menor, particiones, dx);
	printf ("RESULTADO : %f", resultado);

	return 0;
}

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
}
float funcion (float x){
	return x;
}
