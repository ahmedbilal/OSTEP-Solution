#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv, char * envp[])
{
    int fd[2]; // File Descriptor
    
    int first_child_pid = fork();
    
    if (first_child_pid == 0) // first child
    {
        printf("I am first child %d", first_child_pid);
    }
    else if (first_child_pid > 0) // parent of first child
    {
        int second_child_pid = fork();

        if (second_child_pid == 0) // second child
        {

        }
    }
}