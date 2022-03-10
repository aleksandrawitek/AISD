#include <iostream>

using namespace std;

int  t[]={1,2,3,56, 90, 93, 132,142 ,2121};
int n=sizeof(t)/sizeof(t[0]);


int find(int t[], int n, int x)
{
    int p=0,k=n;
    while(p+1<k)
    {
        int c=(p+k)/2;
        if(x<t[c])
            k=c;
        else    
            p=c;
    }
    if(t[p]==x)
        return p;
    else
        return -1;
}



int main()
{
    for(int x:{2,4,7,90,12})
    {
        int i=find(t,n,x);
        if(i>=0)
            cout<<"Element "<< x << " znajduje się w tablicy na miejscu "<<i<<"."<<endl;
        else
            cout<<"Elementu "<< x << " nie ma w tablicy."<<endl;
    }
}


