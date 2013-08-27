#ifndef __RANDOMENGIN_H__
#define __RANDOMENGIN_H__
#include "ParkMiller.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include "math.h"
#include "stdio.h"
//#include "randomc.h"
struct pass {double bullet[3];};
double RandomEngin(int dim,long seed,int Num,std::vector<MJArray>& store);
#endif