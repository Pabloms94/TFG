/**
 * @brief declaracion de la funcion lecturaUnidimensional
 *
 * @file lecturaUnidimensional.h
 * @author Pablo Martin
 */

#ifndef LECTURAUNIDIMENSIONAL_H_
#define LECTURAUNIDIMENSIONAL_H_

/**
 * @brief lecturaUnidimensional servira para leer datos correspondientes a interpolaciones unidimensionales y devuelve el numero de columnas de la matriz.
 * \n\n VARIABLES
 * @param path sera la ruta que indique el archivos desde donde se leen los datos.
 * @param row indica el numero de filas que contiene nuestra matriz.
 * @param col indica el numero de columnas que tiene nuestra matriz.
 * @param mat es la matriz en la cual se introduciran los datos leidos.
 */

int lectura1D(char *path, int row, int col, double mat[row][col]);

#endif /* LECTURAUNIDIMENSIONAL_H_ */
