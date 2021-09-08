#include <bits/stdc++.h>
using namespace std;
#define MAX 105
#define NUM1 1
#define NUM2 5
#define NUM3 11

int dp[MAX] = {0};

int main(){
    dp[0] = 0;
    for(int i = 1;i <= MAX;i++){
        if(i - NUM2 < 0){
            dp[i] = dp[i-NUM1] + 1;
        }
        else if(i - NUM3 < 0){
            dp[i] = min(dp[i-NUM1], dp[i-NUM2]) + 1;
        }
        else{
            int temp = min(dp[i-NUM1], dp[i-NUM2]);
            temp = min(temp, dp[i - NUM3]);
            dp[i] = temp + 1;
        }
    }
    for(int i = 1;i <= MAX;i++){
        cout << "i " << i << " : " << dp[i] << endl;
    }

    system("pause");

    return 0;
}

/*
原题是：
如果一个奇葩国家的钞票面额分别是NUM1、NUM2、NUM3，讨论各种面额(<=MAX)下凑出需要的最少钞票数。
*/

/*
结题思路：f(i)只有可能是在f(I-NUM1)+1,f(I-NUM2)+1,F(I-NUM3)+1中选一个。
    就选最小的就能找到最小面额数!状态转移方程：f(i) = min[f(i-num1),f(i-num2),f(i-num3)]+1;
*/