/**
 * @brief declaracion de la funcion de interpolaciOn unidimensional
 *
 * @file interpolacion.h
 * @author Pablo Martin
 */

#ifndef INTERPOLACION_H_
#define INTERPOLACION_H_

/**
 * @brief interpolar1D calcula interpolaciones de manera bAsica y sencilla.
 * \n\n VARIABLES
 * @param x sera el valor de x para el cual habra que calcular y.
 * @param X es un array de tipo double que contiene la energia .
 * @param Y sera el array de tipo double que contiene los valores de atenuaciOn.
 * @param lit es un entero que indica el numero de elementos de los arrays anteriores.
 */

double interpolar1D(double x, double X[], double Y[], int lit);

#endif /* INTERPOLACION_H_ */
