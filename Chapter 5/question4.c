#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();

    if (rc == 0) // child
    {
        printf("************* Executing Child Process **************\n");
        char * const argv[] = {"ls", NULL};
        char * const envp[] = {NULL};

        // ***************** Uncomment only 1 of these ************************ /

        //execl("/bin/ls", "ls", NULL);
        //execlp("ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, envp);
        
        //execv("/bin/ls", argv);
        //execvp("ls", argv);
        //execvpe("ls", argv, envp); // not declared on my pc. May be work on yours.
    }
    else if (rc > 0) // parent
    {
        wait(NULL);
    }
    else
    {
        fprintf(stderr, "Error occurred during fork()");
    }
}