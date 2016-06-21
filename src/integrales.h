/**
 * @brief declaracion de la funcion integrales
 *
 * @file integrales.h
 * @author Pablo Martín
 */

#ifndef INTEGRALES_H_
#define INTEGRALES_H_


/**
 * @brief dobleIntegral calcula la doble integral que se le pasa a la funcion.
 * \n\n VARIABLES
 * @param verticeMenor hace referencia al valor del extremo inferior de la particion que se toma como referencia. X e Y distinguen la coordenada que almacenan.
 */

double dobleIntegral (double(*f)(double, double), double mayor1, double menor1, double mayor2, double menor2);

#endif /* INTEGRALES_H_ */
