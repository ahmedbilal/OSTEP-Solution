#include<stdio.h>

int main(){
    int *p=NULL;
    printf("%d\n",*p);
    return 0;
}
//Segmentation Fault occur. Mean we are trying to access memory location that is not declared.
