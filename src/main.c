#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cJSON.h"
#include "integrales.h"
#include "interpolacion.h"
#include "funcion.h"

/*
 * @author Pablo Martin Sanchez
 */

void create_objects(double *x, double *y, int i);

/**
 * @brief main
 * @param menor hace referecia al extremo inferior de las integrales.
 * @param mayor hace referecia al extremo superior de las integrales.
 * @warning uno y dos situado en el nombre de los parametros diferencia si los extremos pertenecen a la integral externa o interna.
 */

int main(void) {
	//Variables usadas para las integrales.
	double menor1 = 1;
	double mayor1 = 2;
	double menor2 = 3;
	double mayor2 = 4;
	double resultado;

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
	}
	fclose(f);

	//Integrales
	resultado = dobleIntegral(funcion, mayor1, menor1, mayor2, menor2);
	printf ("RESULTADO INTEGRALES: %lg.\n\n", resultado);

	//Interpolación
	interpolacion = lagrange (energiaInterpolar, energia, atenuacion, i);
	printf ("RESULTADO INTERPOLACIÓN: %lg.\n\n", interpolacion);

	create_objects(energia, atenuacion, i);

	return 0;
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
	free(out);
	fclose(fp);

	fp = fopen("y.json", "w");
	root = cJSON_CreateDoubleArray(y,i);

	out=cJSON_Print(root);
	fputs(out, fp);
	cJSON_Delete(root);
	free(out);

	fclose(fp);

}
