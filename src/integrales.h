/**
 * @brief declaracion de la funcion integrales
 *
 * @file integrales.h
 * @author Pablo Martin
 */

#ifndef INTEGRALES_H_
#define INTEGRALES_H_

/**
 * @brief dobleIntegral calcula la doble integral de la funciOn que se le pasa como argumento.
 * \n\n VARIABLES
 * @param mayor1 hace referencia al valor del límite superior de la integral externa.
 * @param menor1 hace referencia al valor del límite inferior de la integral externa.
 * @param mayor2 hace referencia al valor del límite superior de la integral interna.
 * @param menor2 hace referencia al valor del límite inferior de la integral interna.
 */

double dobleIntegral(double (*f)(double, double), double mayor1, double menor1,
		double mayor2, double menor2);

#endif /* INTEGRALES_H_ */
