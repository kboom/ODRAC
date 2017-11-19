#include "problem.h"

int mm7(double first[][SIZE], double second[][SIZE], double multiply[][SIZE])
{
    register unsigned int i,j,k; //<- OPT 1
    register unsigned int local_size=SIZE; //<- OPT 2
    double sum = 0;
    for (i = 0; i<SIZE ; i++ ) { //rows in multiply <- OPT 3
        for (j=0; j<SIZE; ) {
            for (k=0; k<SIZE; ) {

                sum = sum + first[i][k]*second[j][k] //<- OPT 5 (k<->j)
                      + first[i][k+1]*second[j][k+1]
                      + first[i][k+2]*second[j][k+2]
                      + first[i][k+3]*second[j][k+3]
                      + first[i][k+4]*second[j][k+4]
                      + first[i][k+5]*second[j][k+5]
                      + first[i][k+6]*second[j][k+6]
                      + first[i][k+7]*second[j][k+7];
                multiply[i][j]+=sum; sum=0;

                sum = sum + first[i][k]*second[j+1][k] //<- OPT 5 (k<->j+1)
                      + first[i][k+1]*second[j+1][k+1]
                      + first[i][k+2]*second[j+1][k+2]
                      + first[i][k+3]*second[j+1][k+3]
                      + first[i][k+4]*second[j+1][k+4]
                      + first[i][k+5]*second[j+1][k+5]
                      + first[i][k+6]*second[j+1][k+6]
                      + first[i][k+7]*second[j+1][k+7];
                multiply[i][j+1]+=sum; sum=0;

                sum = sum + first[i][k]*second[j+2][k] //<- OPT 5 (k<->j+2)
                      + first[i][k+1]*second[j+2][k+1]
                      + first[i][k+2]*second[j+2][k+2]
                      + first[i][k+3]*second[j+2][k+3]
                      + first[i][k+4]*second[j+2][k+4]
                      + first[i][k+5]*second[j+2][k+5]
                      + first[i][k+6]*second[j+2][k+6]
                      + first[i][k+7]*second[j+2][k+7];
                multiply[i][j+2]+=sum; sum=0;

                sum = sum + first[i][k]*second[j+3][k] //<- OPT 5 (k<->j+3)
                      + first[i][k+1]*second[j+3][k+1]
                      + first[i][k+2]*second[j+3][k+2]
                      + first[i][k+3]*second[j+3][k+3]
                      + first[i][k+4]*second[j+3][k+4]
                      + first[i][k+5]*second[j+3][k+5]
                      + first[i][k+6]*second[j+3][k+6]
                      + first[i][k+7]*second[j+3][k+7];
                multiply[i][j+3]+=sum; sum=0;

                sum = sum + first[i][k]*second[j+4][k] //<- OPT 5 (k<->j+4)
                      + first[i][k+1]*second[j+4][k+1]
                      + first[i][k+2]*second[j+4][k+2]
                      + first[i][k+3]*second[j+4][k+3]
                      + first[i][k+4]*second[j+4][k+4]
                      + first[i][k+5]*second[j+4][k+5]
                      + first[i][k+6]*second[j+4][k+6]
                      + first[i][k+7]*second[j+4][k+7];
                multiply[i][j+4]+=sum; sum=0;

                sum = sum + first[i][k]*second[j+5][k] //<- OPT 5 (k<->j+5)
                      + first[i][k+1]*second[j+5][k+1]
                      + first[i][k+2]*second[j+5][k+2]
                      + first[i][k+3]*second[j+5][k+3]
                      + first[i][k+4]*second[j+5][k+4]
                      + first[i][k+5]*second[j+5][k+5]
                      + first[i][k+6]*second[j+5][k+6]
                      + first[i][k+7]*second[j+5][k+7];
                multiply[i][j+5]+=sum; sum=0;

                sum = sum + first[i][k]*second[j+6][k] //<- OPT 5 (k<->j+6)
                      + first[i][k+1]*second[j+6][k+1]
                      + first[i][k+2]*second[j+6][k+2]
                      + first[i][k+3]*second[j+6][k+3]
                      + first[i][k+4]*second[j+6][k+4]
                      + first[i][k+5]*second[j+6][k+5]
                      + first[i][k+6]*second[j+6][k+6]
                      + first[i][k+7]*second[j+6][k+7];
                multiply[i][j+6]+=sum; sum=0;

                sum = sum + first[i][k]*second[j+7][k] //<- OPT 5 (k<->j+7)
                      + first[i][k+1]*second[j+7][k+1]
                      + first[i][k+2]*second[j+7][k+2]
                      + first[i][k+3]*second[j+7][k+3]
                      + first[i][k+4]*second[j+7][k+4]
                      + first[i][k+5]*second[j+7][k+5]
                      + first[i][k+6]*second[j+7][k+6]
                      + first[i][k+7]*second[j+7][k+7];
                multiply[i][j+7]+=sum; sum=0;

                k=k+8;
            }
            j=j+8;
        }
    }
    return 0;
}