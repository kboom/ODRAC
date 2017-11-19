#include "problem.h"

int mm4(double first[][SIZE], double second[][SIZE], double multiply[][SIZE])
{
    register unsigned int i,j,k; //<- OPT 1
    register unsigned int local_size=SIZE; //<- OPT 2
    double sum = 0;
    for (i = SIZE; i-- ; ) { //rows in multiply <- OPT 3
        for (j = SIZE; j-- ;) { //columns in multiply
            for (k = SIZE; k-- ; ) { //columns in first and rows in second
                sum = sum + first[i][k]*second[k][j];
            }
            multiply[i][j] = sum;
            sum = 0;
        }
    }
    return 0;
}