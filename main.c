#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

int msleep(long period);

int main() {
    // Clear the screen
    printf("\x1b[2J");

    /* for(int i;;i++) {
        // Move cursor to home position
        //printf("\x1b[H");

        i -= (i >= 10 ? i : 0);
        printf("yupyup%d", i);
        sleep(1);
        // msleep(1000);
    } */

    msleep(1000);
    printf("send help\n");

    return 0;
}

int msleep(long period)
{
    struct timespec ts;
    int res;

    if (period < 0) {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = period / 1000;
    ts.tv_nsec = (period % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}
