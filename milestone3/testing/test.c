#include<stdio.h>
#include<stdlib.h>

int main(){
    int *a = malloc(10*sizeof(int));
    a[0] = 1;
    a[7] = 7;
    a[8] = a[7] + a[0];
    printf("%d\n", a[8]);
    return 0;
}