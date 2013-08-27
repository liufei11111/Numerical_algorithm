#include "RandomEngin.h"
double RandomEngin(int dim,long seed,int Num,std::vector<MJArray>& store){
	int max=dim*Num;
	MJArray temp(dim*Num+1);
	RandomParkMiller sample(max+1,seed);

		sample.GetUniforms(temp);
  store[0].resize(Num);
  store[1].resize(Num);
  store[2].resize(Num);
		for (int j=0;j<Num;j++){
			

			for (int i=0;i<dim;i++)
				store[i][j]=   temp[j*dim+i+1];                   //a.Random();;
		}

	return 0.0;
}