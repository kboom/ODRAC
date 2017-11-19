#ifndef OORA_PERFORMANCE_H
#define OORA_PERFORMANCE_H

typedef struct Performance {

    /* Time variables */
    double dtime;

    /* PAPI variables */
    int * events;
    long long * values;
    int numevents;
    int check;
    float real_time;
    float proc_time;
    float mflops;
    long long flpins;


} Performance;

void startZero(Performance* q);
void stopZero(Performance* q);
void startOne(Performance* q);
void startTwo(Performance* q);
void stopOne(Performance* q);
void stopTwo(Performance* q);

#endif //OORA_PERFORMANCE_H