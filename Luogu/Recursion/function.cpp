#include <iostream>
#define w_m(x,y,z) (num[x][y][z] ? num[x][y][z] : num[x][y][z] = w(x,y,z))
using namespace std;

/*
Date: 2021/4/18 23:07
Author:Zeiton Leibzc
Summary: 
记忆宏的用法 #define w_m(x,y,z) (num[x][y][z] ? num[x][y][z] : num[x][y][z] = w(x,y,z))
define可定义重复函数简单的函数（或许什么联函数也能解决？） main中用到了记忆宏的地方是可以传递值的.
w_m(a-1,b,c)  a-1 b c 会被换为相应的x,y,z 
这就很棒~
*/

int num[25][25][25];

long long w(int a,int b,int c)
{
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a > 20 || b > 20 || c > 20) return w_m(20,20,20);
    if(a < b && b < c) return w_m(a,b,c-1) + w_m(a,b-1,c-1) - w_m(a,b-1,c);

    return w_m(a-1,b,c)+w_m(a-1,b-1,c)+w_m(a-1,b,c-1) - w_m(a-1,b-1,c-1);
}

int main()
{
    long long a,b,c;
    while(cin >> a >> b >> c)
    {
        if(a == -1 && b == -1 && c == -1) break ;
        cout << "w(" << a << "," << b << "," << c << ") = " << w(a,b,c) << endl;
    }

    return 0;
}

