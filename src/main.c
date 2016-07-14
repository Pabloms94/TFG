/*
 * @author Pablo Martin Sanchez
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int main(void) {
	int i, j;
	double resultado;

	printf("\n\nINICIO LECTURA\n\n");

	lectura1D("data/csda/74.csv", &csdaS);

	/*for (i =0; i<2;i++){
		for (j= 0; j<csdaS.col; j++){
			printf("%lf ", csdaS.data[i][j]);
		}
		printf("\n");
	}*/

	lectura1D("data/mu/74.csv", &muS);

	/*for (i =0; i<2;i++){
		for (j= 0; j<muS.col; j++){
			printf("%lf ", muS.data[i][j]);
		}
		printf("\n");
	}*/

	lectura2D("data/fluence/100.csv", &fluenceS);

	/*for (i =0; i<fluenceS.row;i++){
		printf("%lf ", fluenceS.grid[0][i]);
	}

	printf("\n");

	for (j= 0; j<fluenceS.col; j++){
		printf("%lf ", fluenceS.grid[1][j]);
	}*/

	lectura2D("data/cs/74.csv", &csS);

	printf("\n\nFIN LECTURA\n\n");

	resultado = dobleIntegral(fuente, Xmax, 0, 1, Ey/E0);

	printf("\n\nEl resultado es: %lf\n\n", resultado);

	getchar();
	return 0;
}

/**
 * @brief create_objects crea archivos json para exportar los datos a java
 * @param x es el vector de energía que se representara en el eje de las X
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
