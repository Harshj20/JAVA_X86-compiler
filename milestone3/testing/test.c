#include<stdio.h>
int foo(int x){
    int c = x + 1;
    return c;
}
int main(){
    int c = foo(10);
    int d = c + 20;
    printf("%d\n", d);
    return 0;
}