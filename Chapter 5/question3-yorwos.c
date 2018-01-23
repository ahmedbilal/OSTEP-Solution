#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signum) {
    printf("goodbye\n");
    exit(0);
}

int main (int argc, char const *argv[]) {
    int parent_pid = getpid();
    int rc = fork();
    if (rc == 0) //child
    {
        printf("hello\n");
        kill(parent_pid, SIGCONT);
        exit(0);
    }
    else if (rc > 0) // parent
    {
        //  https://www.unix.com/302582537-post2.html?s=c29ed69cf8a6adc4c14984b71e3aa176
        /*  You can sleep "indefinitely" with the pause() function,
            defined in <unistd.h>, which will sleep until you receive
            a signal.You can wake a pause()d thread with pthread_kill() or kill()
            to send some signal that won't kill it (SIGCONT seems appropriate).
        */
        signal(SIGCONT, sig_handler); // install signal handler
        pause();
    }
    else // fork did not succeed
    {
        printf("error\n");
        return 1;
    }
}

