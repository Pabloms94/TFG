/**
 * @brief declaraciOn de los tipos struct que necesitaremos
 *
 * @file structs.h
 * @author Pablo MartIn
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_

struct Data1D{
	double data[2][500];
	int col;
};

struct Data2D{
	double grid[2][500];
	double data[500][500];
	int row, col;
};

extern double Xmax;
extern double E0;
extern double Ey;
extern double Theta;
extern double Phi;

#endif /* STRUCTS_H_ */
