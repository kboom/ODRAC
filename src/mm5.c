#include "problem.h"

int mm5(double first[][SIZE], double second[][SIZE], double multiply[][SIZE])
{
    register unsigned int i,j,k; //<- OPT 1
    //  register unsigned int local_size=SIZE; //<- OPT 2
    register double sum = 0;
    for (i = SIZE; i-- ; ) { //rows in multiply <- OPT 3
        for (j = SIZE; j-- ;) { //columns in multiply
            for (k = 0; k < SIZE; ) {
                if(k<SIZE-8) { //<- OPT 4
                    sum = sum + first[i][k]*second[k][j]
                          + first[i][k+1]*second[k+1][j]
                          + first[i][k+2]*second[k+2][j]
                          + first[i][k+3]*second[k+3][j]
                          + first[i][k+4]*second[k+4][j]
                          + first[i][k+5]*second[k+5][j]
                          + first[i][k+6]*second[k+6][j]
                          + first[i][k+7]*second[k+7][j];
                    k=k+8;
                }
                else {
                    sum = sum + first[i][k]*second[k][j];
                    k++;
                }
            }
            multiply[i][j] = sum;
            sum = 0;
        }
    }
    return 0;
}