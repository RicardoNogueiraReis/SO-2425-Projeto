#define _POSIX_C_SOURCE 199309L

#include <time.h>
#include <sys/time.h>
#include "timeMilis.h"

int createTime(PtTimeMillis timer) {
    if (timer == NULL)
        return TIMER_IS_NULL;
    
    clock_gettime(CLOCK_MONOTONIC, timer);
    return TIMER_SUCCESS;
}

int createTimeFromTimeDiff(PtTimeMillis resultTimer, PtTimeMillis startTimer, PtTimeMillis endTimer) {
    if (resultTimer == NULL || startTimer == NULL || endTimer == NULL)
        return TIMER_IS_NULL;

    resultTimer->tv_sec = endTimer->tv_sec - startTimer->tv_sec;
    resultTimer->tv_nsec = endTimer->tv_nsec - startTimer->tv_nsec;
    return TIMER_SUCCESS;
}

int getTimeInMilis(PtTimeMillis timer, PtMillis milis) {
    if (timer == NULL)
        return TIMER_IS_NULL;

    *milis = (long long) timer->tv_sec * 1000 + (long long) timer->tv_nsec / 1000000;
    return TIMER_SUCCESS;
}