#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define number_of_iter 1000000
#define BILLION 1000000000L

int main()
{
    struct timespec startTime, endTime;
    long sum = 0;
    double avg;

    for (int i = 0; i < number_of_iter; i++)
    {
        clock_gettime(CLOCK_BOOTTIME, &startTime);

        write(fileno(stdout), NULL, 0);

        clock_gettime(CLOCK_BOOTTIME, &endTime);

        /* I don't get this adjustment. I got it from
        https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
        */
        long difference = BILLION * (endTime.tv_sec - startTime.tv_sec) + endTime.tv_nsec - startTime.tv_nsec;
        sum += difference;
    }
    avg = sum / (float)number_of_iter;
    printf("The Avg syscall time is %f nano-seconds.\n", avg);
    return 0;
}