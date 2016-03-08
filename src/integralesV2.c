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
	float menor = 1;
	float mayor = 2.71;
	float particiones = 1000;
	float dx = (mayor - menor) /particiones;

	float resultado = integral(menor, particiones, dx);
	printf ("RESULTADO : %f", resultado);
	return 0;
}

float integral (float menor, float particiones, float dx){
	int i;
	float resultado = 0;

	for(i = 0; i < particiones; i++){
		float verticeMenor = menor + i*dx;
		float valorFuncion = funcion(verticeMenor);
		float area = valorFuncion * dx;
		resultado += area;
	}
	return resultado;
}
float funcion (float x){
	return 1/x;
}
