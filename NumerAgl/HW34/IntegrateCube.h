#ifndef __INTEGRATECUBE_H__
#define __INTEGRATECUBE_H__
#include "RandomEngin.h"
#include "stdlib.h"
struct limites{
	double x[2];
	double y[2];
	double z[2];
};

void ShowVectorMJArray(std::vector<MJArray>&);
double FunctionEval(std::vector<MJArray>&);
#endif 
