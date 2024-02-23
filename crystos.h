#ifndef CRYSTOS_H_
#define CRYSTOS_H_
#include <stdio.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    long frequency; // Frequency in Hertz (cycles per second)
} Clock;

typedef void (*update_t)(void);

/**
 * Simulates a clock tick by sleeping for the duration based on the specified frequency
 * and then calling the provided update function.
 * 
 * @param clock Pointer to a Clock structure containing the clock frequency.
 * @param update Function pointer to the update function to be called on each tick.
 */
void tick(Clock *clock, update_t update);
#endif // !CRYSTOS_H_

#ifdef CRYSTOS_IMPLEMENTATION
void tick(Clock *clock, update_t update) {
    const long nanoseconds_per_second = 1000000000L;
    struct timespec sleepTime;

    // Calculate sleep time based on the frequency
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = nanoseconds_per_second / clock->frequency;

    // Simulate a clock tick by sleeping
    nanosleep(&sleepTime, NULL);

    // clock the cpu
    update();
}
#endif // CRYSTOS_IMPLEMENTATION
