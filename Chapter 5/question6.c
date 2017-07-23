#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();
    
    if (rc == 0) // child
    {
        printf("I am child process. My PID is %d\n", getpid());
        exit(0);
    }
    else if (rc > 0)
    {
        printf("I am parent process. My PID  is %d\n", getpid());
        printf("Return Code value is %d\n", rc);
        int status;
        waitpid(rc, &status, WEXITED);
        WIFEXITED(status);
        printf("Child process successfully exit\n");
    }
    else
    {
        fprintf(stderr, "Error occurred during fork()");
    }
}