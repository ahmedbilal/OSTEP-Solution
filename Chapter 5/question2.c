#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int my_file = open("hello.txt", O_CREAT | O_WRONLY, S_IRWXU);
    
    int rc = fork();

    if (rc == 0)
    {
        const char * child_msg = "Hello, I am child process. Writing on you\n";

        printf("-------------------------------\n");
        printf("Child process\n");
        printf("-------------------------------\n");
        printf("Accessing File Descriptor (file handle): %d\n", my_file);
        write(my_file, child_msg , strlen(child_msg));
    }
    else if (rc > 0)
    {
        const char * parent_msg = "Hello, I am parent process. Writing on you\n";
        printf("-------------------------------\n");
        printf("Parent process\n");
        printf("-------------------------------\n");
        printf("Accessing File Descriptor (file handle): %d\n", my_file);
        write(my_file, parent_msg, strlen(parent_msg));
    }
    close(my_file);
    return 0;
}