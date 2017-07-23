#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        printf("Error occurred during creation of pipe\n");
    }
    int rc = fork();

    if (rc == -1)
    {
        fprintf(stderr, "Error ocurred during fork()");
    }
    else if (rc == 0) // child
    {
        char * msg_to_dad = "Can you hear me dad?";

        close(pipefd[0]); // We don't want to read
        write(pipefd[1], msg_to_dad, strlen(msg_to_dad));
        printf("I am child process\n");
    }
    else
    {
        char * msg_from_child = (char *) malloc(100);
        wait(NULL);
        close(pipefd[1]);
        read(pipefd[0], msg_from_child, 100);
        printf("I am parent process\n");
        printf("I got this msg from my child \"%s\" ", msg_from_child);
        free((void *)msg_from_child);
    }
}