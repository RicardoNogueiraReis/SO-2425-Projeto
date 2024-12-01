#include <sys/time.h>

#define TIMER_SUCCESS 0
#define TIMER_IS_NULL 1

#pragma once

typedef struct timespec TimeMillis;

typedef TimeMillis *PtTimeMillis;

typedef long long Millis;

typedef long long *PtMillis;

/**
 * @brief Creates a TimeStamp for the Current Time 
 * 
 * @param timer The TimeStamp
 * @return int - Success (0) or Error (>0)
 */
int createTime(PtTimeMillis timer);

/**
 * @brief Create a TimeStamp from the Diference of Two Other Timestamps!
 * 
 * @param resultTimer The Result TimeStamp
 * @param startTimer The Begin TimeStamp
 * @param endTimer The End TimeStamp
 * @return int - Success (0) or Error (>0)
 */
int createTimeFromTimeDiff(PtTimeMillis resultTimer, PtTimeMillis startTimer, PtTimeMillis endTimer);

/**
 * @brief Gets the Time in Millis from a TimeStamp
 * 
 * @param timer The TimeStamp
 * @param millis The Time in Millis
 * @return int - Success (0) or Error (>0)
 */
int getTimeInMilis(PtTimeMillis timer, PtMillis millis);