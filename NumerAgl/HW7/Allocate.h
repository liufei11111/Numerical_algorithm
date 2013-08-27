#ifndef __ALLOCATE_H__
#define __ALLOCATE_H__
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
double ** allocate_real_matrix(int tamx,int tamy,int zero);
double **free_real_matrix(double **v, int tam);
#endif
