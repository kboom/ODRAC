#include "performance.h"
#include <stdio.h>
#include <stdlib.h>
#include <papi.h>
#include <sys/time.h>

static double gtod_ref_time_sec = 0.0;

double dclock() {
    double the_time, norm_sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    if (gtod_ref_time_sec == 0.0)
        gtod_ref_time_sec = (double) tv.tv_sec;
    norm_sec = (double) tv.tv_sec - gtod_ref_time_sec;
    the_time = norm_sec + tv.tv_usec * 1.0e-6;
    return the_time;
}


void startZero(Performance* q) {
    q->dtime = dclock();
}

void stopZero(Performance* q) {
    double dtime = dclock() - q->dtime;
    printf("Time: %le \n", dtime);
}

void startOne(Performance* q) {
    int retval = PAPI_flops(&q->real_time, &q->proc_time, &q->flpins, &q->mflops);
    if (retval != PAPI_OK) {
        char * errorstring = PAPI_strerror(retval);
        fprintf(stderr, errorstring);
        fprintf(stderr, "\n");
        free(errorstring);
        exit(1);
    }
    printf("PAPI started\n");
}

void startTwo(Performance* q) {
    q->numevents = 2;
    q->events = malloc(sizeof *q->events * q->numevents);
    q->events[0] = PAPI_LD_INS;
    q->events[1] = PAPI_SR_INS;
    PAPI_library_init(q->check);
    int retval = PAPI_start_counters(q->events, q->numevents);
    if (retval != PAPI_OK) {
        char * errorstring = PAPI_strerror(retval);
        fprintf(stderr, errorstring);
        fprintf(stderr, "\n");
        free(errorstring);
        exit(1);
    }
    printf("PAPI started\n");
}

void stopOne(Performance* q) {
    int retval = PAPI_flops(&q->real_time, &q->proc_time, &q->flpins, &q->mflops);
    if (retval != PAPI_OK) {
        char * errorstring = PAPI_strerror(retval);
        fprintf(stderr, errorstring);
        fprintf(stderr, "\n");
        free(errorstring);
        exit(1);
    }
    printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n", q->real_time, q->proc_time, q->flpins, q->mflops);
}

void stopTwo(Performance* q) {
    q->values = malloc(sizeof *q->values * q->numevents);
    int retval = PAPI_stop_counters(q->values, q->numevents);
    if (retval != PAPI_OK) {
        char * errorstring = PAPI_strerror(retval);
        fprintf(stderr, errorstring);
        fprintf(stderr, "\n");
        free(errorstring);
        exit(1);
    }
    printf("Mem loads: %lld Mem store: %lld\n", q->values[0], q->values[1]);
    free(q->values);
    free(q->events);
}
