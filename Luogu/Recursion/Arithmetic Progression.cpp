#include <iostream>
using namespace std;
/*
Date:2021/4/20
Author:曾志存
Detail：|a1|,|a2| <= 10^6
3 <= n <= 10^6
所以d_max = 10^6,n_max = 10^6
这样，结果可能是10^18次方数量级
需要开long long
Knowledge point:INT_MAX = 2^31 - 1 = 2^31 = 2,147,483,648 = 2×10^9
LONG LONG_MAX = 9×10^18
*/
int main()
{
    int a1,a2,n;//等差数列第一项，第二项，项数
    cin >> a1 >> a2 >> n;
    cout << a1*n + (n*n - n)*(a2 - a1) / 2;

    return 0;
}