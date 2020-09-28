#include <iostream>

using namespace std;

int main()
{
    char A[]="Finding";
    int H=0, x=0;

    for(int i=0; A[i]!='\0'; i++){
        x=1;
        if(A[i]>=65&&A[i]<=90)
            x=x<<(A[i]-65);
        else
            x=x<<(A[i]-97);
        if((H&x)>0)
            cout<<A[i]<<" is Duplicate"<<endl;
        else
            H=H|x;
    }

    return 0;
}

