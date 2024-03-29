# Chapter 5

## Question 1

### Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?

**fork()** creates copy of parent process.
However, child and parent process have their
own private address space exclusive of each
other. Both process (child and parent) can't
interfare in each other's address space (memory).

So, each maintain their own copy of variables.

## Question 2

### Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?


Both child and parent can access the file descriptor opened using **open()**.

Both are able to write to the file but the order in which they do is un-deterministic (*if we don't use **wait()***).



## Question 3

### Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?

~~Yes, It can be possible (although not sure how much reliable it is) to ensure that child process always print first without **wait()**.
**See my question3.c code**.~~

**See question3-yorwos.c suggested by [yorwos](https://github.com/yorwos) :smiley:**

## Question 4

### Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including execl(), execle(), execlp(), execv(), execvp(), and execvP(). Why do you think there are so many variants of the same basic call?

See question4.c
Each variant serves its own purpose (altough they can be interchangbly used with little modification).
```c
#include <unistd.h>

int execl(const char *filepath, const char* arg1, const char* arg2,...)
int execlp(const char *filename, const char* arg1, const char* arg2,...)
int execle(const char *filepath, const char* arg1, const char* arg2,..., char* const envp[])
int execv(const char* filepath, char*argv[])
int execvp(const char* filename, char *argv[])
int execve(const char* filepath, char* argv[], char* const envp[])
```
1. **execl** and **execv** are nearly identical (have very little difference). They can execute commands given absolute path.
1. **execlp** and **execvp** are nearly identical. They can execute commands included within the **PATH** enviornment given the command name.
1. **execle** and **execvpe** are nearly identical. They can execute commands within specific enviornments.

### Rules

1. Functions having **l** in their name need argument seperated by commas.
1. Function having **v** in their name need arguments as (v -> vector (array))

```c
char * array[]
```

1. Function having **e** need environment argument

```c
char * array[]
```

## Question 5

### Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?

**wait():** on success, returns  the  process ID of the terminated child;
on error, -1 is returned.

If we use **wait()** in child process then **wait()** returns -1. Because, there is no child
of child. So, there is no wait for any process (child process) to exit.

## Question 6

### Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?

**waitpid()** is used when we want to wait or a specific child process rather than aiting for all child processes to exit.It also allow us to specify more behaviours.

## Question 7

### Write a program that creates a child process, and then in the child closes standard output (STDOUT FILENO). What happens if the child calls printf() to print some output after closing the descriptor?

If we close **stdout** file descriptor we can't be
able to write something on the screen using
**printf()**. However no error would occurred.

## Question 8

### Write a program that creates two children, and connects the standard output of one to the standard input of the other, using the pipe() system call.

We create a pipe with the pipe() system call, exiting if unsuccessful.
We create the first child, which we call A, with a fork() call, then, in the section of code running for the parent, we make a second fork() call to make the second child, which we call B.
Child A uses dup2 to make stdout point to the write end of the pipe and passes a string to the write end of the pipe.
Child B uses dup2 to make stdin point to the read end of the pipe and reads from the read end of the pipe.
This connects the stdout of A to the stdin of B.

### Note

Please email me if you have better explaination for the question or you have some suggestions.

Click this [ahmedbilal96@gmail.com](mailto:ahmedbilal96@gmail.com) to email me.
