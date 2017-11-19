#include "problem.h"
#include "measurements.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    int i, j, iret;
    double first[SIZE][SIZE];
    double second[SIZE][SIZE];
    double multiply[SIZE][SIZE];

    initializeMeasurements(argc, argv);

    /* Initalize matrices */
    for (i = 0; i < SIZE; i++) { //rows in first
        for (j = 0; j < SIZE; j++) { //columns in first
            first[i][j] = i + j;
            second[i][j] = i - j;
            multiply[i][j] = 0.0;
        }
    }

    startMeasurements();

    int solver = atoi(argv[1]);
    switch (solver) {
        case 1:
            iret = mm1(first, second, multiply);
            break;
        case 2:
            iret = mm2(first, second, multiply);
            break;
        case 3:
            iret = mm3(first, second, multiply);
            break;
        case 4:
            iret = mm4(first, second, multiply);
            break;
        case 5:
            iret = mm5(first, second, multiply);
            break;
        case 51:
            iret = mm5a(first, second, multiply);
            break;
        case 52:
            iret = mm5b(first, second, multiply);
            break;
        case 6:
            iret = mm6(first, second, multiply);
            break;
        case 7:
            iret = mm7(first, second, multiply);
            break;
        case 8:
            iret = mm8(first, second, multiply);
            break;
        case 9:
            iret = mm9(first, second, multiply);
            break;
        default:
            exit(1);
    }

    stopMeasurements();

    /* Checking part of the code. Proper value is 2.932020e+12 */
    double mcheck = 0.0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mcheck += multiply[i][j];
        }
    }
    printf("check %le \n", mcheck);
    fflush(stdout);

    return iret;
}


