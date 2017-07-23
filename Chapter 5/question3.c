#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define true 1
#define false 1
int main()
{
    int backend_file = open("backend_file.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    int rc = fork();

    if (rc == 0) // child process
    {
        write(backend_file, "true", 4);
        printf("I am child process\n");
        printf("hello\n");
        close(backend_file);
    }
    else if (rc > 0)
    {
        char buffer[4];
        buffer[4] = '\0';
        while (strcmp(buffer, "true\0") != 0)
        {
            // I am closing and opening file again so that our program can see updated content.
            close(backend_file);
            backend_file = open("backend_file.txt", O_CREAT | O_RDWR, S_IRWXU);
            read(backend_file, buffer, 4);
            usleep(10 * 1000); // sleep for 10 milli-seconds
        }

        printf("I am parent process\n");
        printf("goodbye\n");
    }
    close(backend_file);
    return 0;
}