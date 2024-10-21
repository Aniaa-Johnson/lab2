#include <sys/time.h>

double elapsed_time(struct timeval* start_time, struct timeval* end_time){
    //TODO: return the difference between end_time and start_time.
    double startTimeMicro = start_time->tv_sec*1000000 + start_time->tv_usec; 
    double endTimeMicro =end_time->tv_sec*1000000 + end_time->tv_usec;
    return (endTimeMicro-startTimeMicro)/1000000.00;
}
