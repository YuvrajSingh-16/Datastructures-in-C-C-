#include <stdio.h>
#include <stdlib.h>

int f[10];

int rfib(int n){
    if(n<=1)
        return n;
    return rfib(n-1)+rfib(n-2);
}

int mfib(int n){
    if(n<=1){
        f[n]=n;
        return n;
    }else{
        if(f[n-1]==-1){
            f[n-1]=mfib(n-1);
        }
        if(f[n-2]==-1){
            f[n-2]=mfib(n-2);
        }
        return f[n-1]+f[n-2];
    }
}
int main()
{   for(int i=0;i<10;i++){f[i]=-1;}
    printf("Hello world!\n");
    printf("%d", mfib(9));
    printf("%d", rfib(9));

    return 0;
}
