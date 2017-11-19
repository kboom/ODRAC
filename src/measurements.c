#include <stdlib.h>
#include "performance.h"

static int measure = 0;
static Performance perf;

void startMeasurements() {
    switch(measure) {
        case 0:
            startZero(&perf);
            break;
        case 1:
            startOne(&perf);
            break;
        case 2:
            startTwo(&perf);
            break;
        default:
            exit(1);
    }
}

void stopMeasurements() {
    switch(measure) {
        case 0:
            stopZero(&perf);
            break;
        case 1:
            stopOne(&perf);
            break;
        case 2:
            stopTwo(&perf);
            break;
        default:
            exit(1);
    }
}

void initializeMeasurements(int argc, const char *const *argv) {
    if (argc > 2) {
        measure = atoi(argv[2]);
    }
}

