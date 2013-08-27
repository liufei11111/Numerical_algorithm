#include "Allocate.h"
double **allocate_real_matrix(int tam,int zero) {
 
    int i, j, n = tam, m = tam;
    double **v;         // pointer to the vector
 
    // allocates one vector of vectors (matrix)
    v = (double**) malloc(n * sizeof(double*));
 
    if (v == NULL) {
        printf ("** Error in matrix allocation: insufficient memory **");
        return (NULL);
    }
 
    // allocates each row of the matrix
    for (i = 0; i < n; i++) {
        v[i] = (double*) malloc(m * sizeof(double));
 
        if (v[i] == NULL) {
            printf ("** Error: Insufficient memory **");
            free_real_matrix(v, n);
            return (NULL);
        }
 
        // initializes the matrix with zeros
        if (zero == 0) {
            for (j = 0; j < m; j++)
                v[i][j] = 0.0;
        }
 
        // initializes the matrix with random values between 0 and 10
        else {
           
                for (j = 0; j < m; j++) {
                   
                    v[i][j] = log10((double)i+13*j+5);
                }
            }
        }
   
 
    return (v);     // returns the pointer to the vector. 
}
double **free_real_matrix(double **v, int tam) {
 
    int i;
 
    if (v == NULL) {
        return (NULL);
    }
 
    for (i = 0; i < tam; i++) { 
        if (v[i]) { 
            free(v[i]); // frees a row of the matrix
            v[i] = NULL;
        } 
    } 
 
    free(v);         // frees the pointer /
    v = NULL;
 
    return (NULL);   //returns a null pointer /
}