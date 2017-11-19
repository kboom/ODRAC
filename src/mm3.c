#include "problem.h"

int mm3(double first[][SIZE], double second[][SIZE], double multiply[][SIZE])
{
    register unsigned int i,j,k; //<- OPT 1
    register unsigned int local_size=SIZE; //<- OPT 2
    double sum = 0;
    for (i = 0; i < local_size; i++) { //rows in multiply
        for (j = 0; j < local_size; j++) { //columns in multiply
            for (k = 0; k < local_size; k++) { //columns in first and rows in second
                sum = sum + first[i][k]*second[k][j];
            }
            multiply[i][j] = sum;
            sum = 0;
        }
    }
    return 0;
}