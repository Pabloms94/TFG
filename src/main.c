#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "integrales.h"
#include "lecturaUnidimensional.h"
#include "lecturaBidimensional.h"
#include "structs.h"
#include "llenar.h"
#include "fuente.h"

void create_objects(double *x, double *y, int i);
/*
 * @brief Clase Main.
 * @author Pablo Martin Sanchez.
 */
int main(int argc, char *argv[]) {
	int i;
	double eIntervalo = 4, resultado, x[500], y[500];

	if (argc != 6) {
		printf("\nFaltan argumentos: xpectraC.exe + E0 + theta + phi + E_min + E_intervalo.\n");
		return -1;
	}

	E0 = atof(argv[1]);
	Theta = atof(argv[2]);
	Phi = atof(argv[3]);
	Ey = atof(argv[4]);
	eIntervalo = atof(argv[5]);

	lectura1D("data/csda/74.csv", &csdaS);

	lectura1D("data/mu/74.csv", &muS);

	lectura2D("data/fluence/100.csv", &fluenceS);

	lectura2D("data/cs/74.csv", &csS);

	i = 0;
	while (Ey < E0) {
		x[i] = Ey;
		resultado = dobleIntegral(fuente, Xmax, 0.1, 1, Ey / E0);
		y[i] = resultado;
		Ey += eIntervalo;
		i++;
	}

	create_objects(x, y, i);

	return 0;
}

/**
 * @brief create_objects crea archivos json para exportar los datos a java.
 *
 * @author Pablo Martin Sanchez.
 *
 * @param x es el vector de energía que se representara en el eje de las X.
 * @param y es el vector de atenuacion que se representara en el eje de las Y.
 * @param i indica el numero de elementos de los arrays.
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
