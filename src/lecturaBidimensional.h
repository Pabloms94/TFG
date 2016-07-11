/**
 * @brief declaracion de la funcion lecturaBidimensional
 *
 * @file lecturaBidimensional.h
 * @author Pablo Martin
 */

#ifndef LECTURABIDIMENSIONAL_H_
#define LECTURABIDIMENSIONAL_H_

/**
 * @brief lecturaBidimensional servira para leer datos correspondientes a interpolaciones bidimensionales y devuelve el numero de
 * elementos por fila y columna de la matriz.
 * \n\n VARIABLES
 * @param path sera la ruta que indique el archivos desde donde se leen los datos.
 * @param row indica el numero de filas que contiene nuestra matriz grid.
 * @param col indica el numero de columnas que tiene nuestra matriz grid, y a la vez el tamaño de la matriz cuadrada resultante de
 * la lectura.
 * @param grid es la matriz que contendra los valores de X e Y que se conjuntaran con los Z a leer.
 * @param mat es la matriz en la cual se introduciran los datos leidos.
 */

int lectura2D(char *path, struct Data2D *myStruct);

#endif /* LECTURABIDIMENSIONAL_H_ */
