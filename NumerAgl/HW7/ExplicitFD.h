#ifndef __ExplicitFD_H__
#define __ExplicitFD_H__
#include "Matrix.h"
#include "stdio.h"
using namespace std;
struct SpaceSpan{double xStart;double xEnd;};
struct TimeSpan{double tStart;double tEnd;};
double BC(double, double);
double IC(double, double);
void Boundary(Matrix&,double(double x,double t),SpaceSpan,TimeSpan);
void InitialC(Matrix&,double(double x,double t),SpaceSpan,TimeSpan,double);
void FDForward(Matrix&,SpaceSpan,TimeSpan,double);
void ExportEveryP(Matrix&,int);
#endif
