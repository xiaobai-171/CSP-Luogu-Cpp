#include <iostream>
using namespace std;
/*
Date:2021/4/24 21:48
Author:曾志存
Details: 
1、像本节做过的前几道题目一样，剪枝，将大量重复的操作直接记下来，
用空间换时间。
2、另外，台阶问题f(n,k) = f(n-1,k) + f(n-2,k)……+f(n-k,k)
前面的系数都是一，因为到了要区分来看，到了n-1它本身就包括了先到n-2再到n-1的情况，所以n-2到n不能经过n-1，
不然这一级（n-2到n-1）会被重复计算
*/
int n,k;
long long num[100005] = {0};

int f(int n,int k)
{
    long long result = 0;
    if(n == 1 || n==0)
        return 1;
    for(int i=1;i <= k;i++)
    {
        if(n-i >= 0) 
        {
            if(!num[n-i])
                num[n-i] = f(n-i,k);
            result += num[n-i];
        }
        else    
            break ;
    }

    return result % 100003;
}

int main()
{
    cin >> n >> k;
    cout << f(n,k);

    return 0;
}