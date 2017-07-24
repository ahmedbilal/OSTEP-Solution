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
    else if (rc == 0) // first child process
    {
        close(pipefd[0]); // We don't want to read
        dup2(pipefd[1], fileno(stdout)); // Redirecting pipe_write <- stdout
    
        printf("I am first child process\n");

        exit(0);
    }
    else
    {
        int rc_2 = fork();

        if (rc_2 == -1)
        {
            fprintf(stderr, "Error occurred during fork() for 2nd process\n");
        }
        else if (rc_2 == 0) // 2nd Child
        {
            char * buffer = (char *)malloc(100);
            close(pipefd[1]); // I don't want to write
            
            read(pipefd[0], buffer, 100); // pipefd[0] -> buffer
            
            if (write(fileno(stdin), buffer, 100) == -1)
            {
                printf("Some error occurred during writing to std_out\n");
            }

            printf("I am second child\n");
            printf("OUTPUT of FIRST CHILD: %s", buffer);
            free((void *)buffer);
            exit(0);
        }
        else
        {
            char * std_out_of_first_child = (char *) malloc(100);
            wait(NULL);
            close(pipefd[1]); // We don't want to write anything
            read(pipefd[0], std_out_of_first_child, 100);
            printf("I am parent process and facilitating redirection of 1st child\nprocess std_output to 2nd child process std_input\n");
            free((void *)std_out_of_first_child);
        }
        
    }
}