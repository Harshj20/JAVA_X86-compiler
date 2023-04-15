#include<stdio.h>
int foo(int x){
    int c = x + 1;
    return c;
}
int main(){
    int z = foo(10);
    int l = z + 20;
    printf("%d\n", l);
    return 0;
}