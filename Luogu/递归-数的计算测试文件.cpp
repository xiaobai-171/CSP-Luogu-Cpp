#include <iostream>
using namespace std;
int f[1001];
int main()
{
    int n;
    cin>>n;
    f[1]=1;
    for(int i=2;i<=n;i++)// n 
    {
            f[i]=f[i-1];
            if(i%2==0)// 
                f[i]+=f[i/2];
    }
    cout<<f[n];
    return 0;
} 
