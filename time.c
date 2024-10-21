#include <sys/time.h>
#include "lab2.h"

// Function to calculate the elapsed time
double elapsed_time(struct timeval* start, struct timeval* end) {
    double start_sec = start->tv_sec + (start->tv_usec / 1000000.0);
    double end_sec = end->tv_sec + (end->tv_usec / 1000000.0);
    return end_sec - start_sec;
}
