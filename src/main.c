/*
 * @author Pablo Martin Sanchez
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "cJSON.h"
#include "integrales.h"
#include "interpolacion.h"
#include "funcion.h"
#include "lecturaUnidimensional.h"
#include "lecturaBidimensional.h"
#include "structs.h"
#include "llenar.h"
#include "fuente.h"

void create_objects(double *x, double *y, int i);

/**
 * @brief main
 */

int main(int argc, char *argv[]) {
	int i;
	FILE *f;
	char x[5000], y[5000], valorEy[20], valorRes[100], coma[3] = ",";
	double eIntervalo = 5, resultado;

	printf("ANTES ASIGNACION\n\n");

	if (argc != 6){
		printf("\nFaltan argumentos: a.exe + E0 + theta + phi + E_min + E_intervalo.\n");
		//return -1;
	}

	/*E0 = atof(argv[1]);
	Theta = atof(argv[2]);
	Phi = atof(argv[3]);
	Ey = atof(argv[4]);
	eIntervalo = atof(argv[5]);
*/
	printf("\n\nE0: %lf theta: %lf phi: %lf E_min: %lf E_intervalo: %lf\n\n", E0, Theta, Phi, Ey, eIntervalo);


	printf("\n\nINICIO LECTURA\n\n");

	lectura1D("data/csda/74.csv", &csdaS);

	lectura1D("data/mu/74.csv", &muS);

	lectura2D("data/fluence/100.csv", &fluenceS);

	lectura2D("data/cs/74.csv", &csS);

	printf("\n\nFIN LECTURA\n\n");

	i=0;
	while(Ey < E0){
		sprintf(valorEy, "%lf", Ey);
		printf("\n\nVALOR EY: %s.\n\n", valorEy);
		strcat(x,valorEy);
		resultado = dobleIntegral(fuente, Xmax, 0.1, 1, Ey/E0);
		sprintf(valorRes, "%lf", resultado);
		strcat(y,valorRes);
		printf("\n\nEl resultado %d es: %lf\n\n", i,resultado);
		if (Ey + eIntervalo < E0){
			strcat(x,coma);
			strcat(y,coma);
		}
		Ey += eIntervalo;
		i++;
	}

	f = fopen("results.csv", "w");
	fprintf(f,"%s\n", x);
	fprintf(f,"%s\n", y);

	fclose(f);

	return 0;
}

/**
 * @brief create_objects crea archivos json para exportar los datos a java
 * @param x es el vector de energ�a que se representara en el eje de las X
 * @param y es el vector de atenuacion que se representara en el eje de las Y
 * @param i indica el numero de elementos de los arrays
 */

void create_objects(double *x, double *y, int i) {
	FILE *fp;
	cJSON *root;
	char *out;

	fp = fopen("x.json", "w");

	root = cJSON_CreateDoubleArray(x, i);
	out = cJSON_Print(root);
	fputs(out, fp);
	cJSON_Delete(root);
	free(out);
	fclose(fp);

	fp = fopen("y.json", "w");
	root = cJSON_CreateDoubleArray(y, i);

	out = cJSON_Print(root);
	fputs(out, fp);
	cJSON_Delete(root);
	free(out);

	fclose(fp);

}
