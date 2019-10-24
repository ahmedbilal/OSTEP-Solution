#include <stdlib.h>
#include <stdio.h>

typedef unsigned char byte;

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Need one arg.\n");
        return 1;
    }   
    
    int n_mb_requested = atoi(argv[1]);
    int mb = 1 << 20; 
    int arr_size = mb * n_mb_requested;
    byte* arr = (byte*) malloc(arr_size);
    printf("Running with %ld bytes\n", arr_size);

    int cur;
    while (1)
        for (cur = 0; cur < arr_size; cur++)
            arr[cur] += 1;

    return 0;
}

