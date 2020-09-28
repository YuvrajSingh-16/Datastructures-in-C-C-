#include <stdio.h>
#include <stdlib.h>

int fact(int n){
    if(n==1 || n==0){
        return 1;
    }
    return fact(n-1)*n;
}

int nCr(int n, int r){
    if(r==0 || n==r)
        return 1;
    return nCr(n-1, r-1) + nCr(n-1, r);
}

int NcR(int N, int R){
    int num=1, den=1;
    num=fact(N);
    den=fact(R)*fact(N-R);
    return num/den;
}

int main()
{
    printf("%d\n", nCr(12, 12));
    printf("%d", NcR(12, 1));

    return 0;
}
