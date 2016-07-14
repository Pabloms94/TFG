/**
 * @brief declaraciOn de los tipos struct que necesitaremos
 *
 * @file structs.h
 * @author Pablo MartIn
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct Data1D{
	double data[2][500];
	int col;
}Data1D;

typedef struct Data2D{
	double grid[2][500];
	double data[500][500];
	int row, col;
}Data2D;

extern double Xmax;
extern double E0;
extern double Ey;
extern double Theta;
extern double Phi;

extern Data1D muS;
extern Data1D csdaS;
extern Data2D fluenceS;
extern Data2D csS;

#endif /* STRUCTS_H_ */
