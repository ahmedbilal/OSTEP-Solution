#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) // child process
    {
        int wc = wait(NULL);
        printf("I am child process\n");
        printf("Return code from wait() is %d\n", wc);
    }
    else if (rc > 0) // parent process
    {
        printf("I am parent process\n");
    }
    else
    {
        fprintf(stderr, "Error Occurred during fork()");
    }
}