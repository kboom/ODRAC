#include "problem.h"

int mm6(double first[][SIZE], double second[][SIZE], double multiply[][SIZE])
{
    register unsigned int i,j,k; //<- OPT 1
    //  register unsigned int local_size=SIZE; //<- OPT 2
    register double sum = 0;
    for (i = SIZE; i-- ; ) { //rows in multiply <- OPT 3
        for (j = SIZE; j-- ;) { //columns in multiply
            for (k=0; k<SIZE; ){
                if(k<SIZE-8) { //<- OPT 4
                    sum = sum + first[i][k]*second[j][k] //<- OPT 5 (k<->j)
                          + first[i][k+1]*second[j][k+1]
                          + first[i][k+2]*second[j][k+2]
                          + first[i][k+3]*second[j][k+3]
                          + first[i][k+4]*second[j][k+4]
                          + first[i][k+5]*second[j][k+5]
                          + first[i][k+6]*second[j][k+6]
                          + first[i][k+7]*second[j][k+7];
                    k=k+8;
                }
                else {
                    sum = sum + first[i][k]*second[j][k];
                    k++;
                }
            }
            multiply[i][j] = sum;
            sum=0.0;
        }
    }
    return 0;
}