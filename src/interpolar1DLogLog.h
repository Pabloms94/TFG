/**
 * @brief declaracion de la funcion de interpolacion
 *
 * @file interpolar1DLogLog.h
 * @author Pablo Martin
 */

#ifndef INTERPOLAR1DLOGLOG_H_
#define INTERPOLAR1DLOGLOG_H_

/**
 * @brief interpolar1DLogLog calcula interpolaciones utilizando logaritmos y devolviendo su exponenciaciOn.
 * \n\n VARIABLES
 * @param x sera el valor de x para el cual habra que calcular y.
 * @param X es un array de tipo double que contiene la energia .
 * @param Y sera el array de tipo double que contiene los valores de atenuacion.
 * @param lit es un entero que indica el numero de elementos de los arrays anteriores.
 */

double interpolar1DLogLog(double x, double X[], double Y[], int lit);








#endif /* INTERPOLAR1DLOGLOG_H_ */
