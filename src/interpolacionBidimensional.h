/**
 * @brief declaracion de la funcion de interpolacion bidimensional
 *
 * @file interpolacionBidimensional.h
 * @author Pablo Martin
 */

#ifndef INTERPOLACIONBIDIMENSIONAL_H_
#define INTERPOLACIONBIDIMENSIONAL_H_

/**
 * @brief interpolar2D calcula interpolaciones en el espacio.
 * \n\n VARIABLES
 * @param x1a sera el vector con los valores de las coordenadas X.
 * @param x2a es un array de tipo double que contiene los valores de la coordenada Y.
 * @param y sera la matriz que contenga los valores de z en función de x e y.
 * @param n1 es un entero que indica el numero de elementos del vector x1a.
 * @param n2 es un entero que indica el numero de elementos del array x2a.
 * @param x1 es un entero que indica el valor de la coordenada X para la cual se va a buscar Z.
 * @param x2 es un entero que indica el valor de la coordenada Y para la cual se va a buscar Z.
 */
double interpolar2D(double* x1a, double* x2a, double** y, int n1, int n2, double x1, double x2);


#endif /* INTERPOLACIONBIDIMENSIONAL_H_ */
