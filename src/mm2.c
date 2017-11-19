#include "problem.h"

int mm2(double first[][SIZE], double second[][SIZE], double multiply[][SIZE])
{
    register unsigned int i,j,k; //<- OPT 1
    double sum = 0;
    for (i = 0; i < SIZE; i++) { //rows in multiply
        for (j = 0; j < SIZE; j++) { //columns in multiply
            for (k = 0; k < SIZE; k++) { //columns in first and rows in second
                sum = sum + first[i][k]*second[k][j];
            }
            multiply[i][j] = sum;
            sum = 0;
        }
    }
    return 0;
}