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
#include "cJSON.h"

float dobleIntegral (float menor1, float mayor2, float menor2, float particiones, float dx);
float funcion (float x, float y);
double newton (int n, double *x, double *y, double interpolar);
void create_objects(double *x, double *y, int i);

/**
 * @brief main
 * @param menor hace referecia al extremo inferior de las integrales.
 * @param mayor hace referecia al extremo superior de las integrales.
 * @warning uno y dos situado en el nombre de los parametros diferencia si los extremos pertenecen a la integral externa o interna.
 */

int main(void) {
	//Variables usadas para las integrales.
	float menor1 = 1;
	float mayor1 = 2;
	float menor2 = 3;
	float mayor2 = 4;
	float particiones = 1000;
	float dy;
	float resultado;

	//Variables usadas para la interpolación
	/*float x[] = {-3, -2, 0, 4};
	float y[] = {5, 8, 4, 2};
	*/

	double energia[60];
	double atenuacion[60];
	double absorcion[60];
	int i = 0;
	double energiaInterpolar = 20;
	double interpolacion;

	FILE* f= fopen("../mu/mu74.csv","r");

		while (fscanf(f,"%lg,%lg,%lg\n",&energia[i],&atenuacion[i],&absorcion[i])!=EOF){
			printf("Lectura: a=%lf, b=%lf,c=%lf\n",energia[i],atenuacion[i],absorcion[i]);
			i++;
			printf("i = %d\n", i);
	}
	fclose(f);

	//Integrales
	dy = (mayor1 - menor1) /particiones;
	resultado = dobleIntegral(menor1, mayor2, menor2, particiones, dy);
	printf ("RESULTADO INTEGRALES: %f.\n\n", resultado);

	//Interpolación
	interpolacion = newton (i, energia, atenuacion, energiaInterpolar);
	printf ("RESULTADO INTERPOLACIÓN: %lg.\n\n", interpolacion);

	create_objects(energia, atenuacion, i);

	return 0;
}

/**
 * @brief dobleIntegral calcula la doble integral que se le pasa a la funcion.
 * \n\n VARIABLES
 * @param verticeMenor hace referencia al valor del extremo inferior de la particion que se toma como referencia. X e Y distinguen la coordenada que almacenan.
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


/*
 * @brief funcion define la funcion que calculamos en la integral
 */
float funcion (float x, float y){
	return x*y;
}

/**
 * @brief newton calcula interpolaciones siguiendo el metodo Newton.
 * \n\n VARIABLES
 * @param difDiv es la tabla que contiene las diferencias divididas necesarias (coeficientes polinomio).
 */
double newton (int n, double *x, double *y, double interpolar){
	double difDiv[n][n];
	double termino;
	double resultado;
	int i, j;

	for (i = 0; i < n; i++){
		difDiv[i][0] = y[i];
	}

	for (j = 1; j < n; j++){
		for (i = 0; i < n-j; i++){
			difDiv[i][j] = (difDiv[i+1][j-1] - difDiv[i][j-1])/(x[i+j] - x[i]);
		}
	}

	termino = 1;
	resultado = difDiv[0][0];
	for (i = 0; i < n-1; i++){
		termino = termino*(interpolar - x[i]);
		resultado = resultado + difDiv[0][i+1] * termino;
	}

	return resultado;
}

/*
 * @brief create_objects crea archivos json para exportar los datos a java
 * @param x es el vector de energía que se representara en el eje de las X
 * @param y es el vector de atenuacion que se representara en el eje de las Y
 * @param i indica el numero de elementos de los arrays
 */

void create_objects(double *x, double *y, int i)
{
	FILE *fp;
	cJSON *root;
	char *out;

	fp = fopen ("x.json", "w");

	root = cJSON_CreateDoubleArray(x,i);
	out=cJSON_Print(root);
	fputs(out, fp);
	cJSON_Delete(root);
	printf("%s\n",out);
	free(out);
	fclose(fp);

	fp = fopen("y.json", "w");
	root = cJSON_CreateDoubleArray(y,i);

	out=cJSON_Print(root);
	fputs(out, fp);
	cJSON_Delete(root);
	printf("%s\n",out);
	free(out);

	fclose(fp);

}
