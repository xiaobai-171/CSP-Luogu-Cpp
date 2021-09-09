#include <iostream>
#include <algorithm>
#define MAX 100'0010
using namespace std;

int Xi[MAX] = {0};
int A[MAX] = {0};
int M = 0;

int X(int i){
    int value = 0;
    for(int j = 1;j <= i - 1;j++){
        value += A[j];
    }
    return (i - 1) * M - value;
}


int main(){
    int n;
    while(scanf("%d", &n) == 1){
        int ans = 0;
        M = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d", &A[i]);
            M += A[i];
        }
        M /= n;
        for(int i = 1;i <= n;i++){
            Xi[i] = X(i);
        }
        sort(Xi+1,Xi+n+1);
        int X1 = (Xi[(n+1)/2] + Xi[(n+1)/2]) / 2;
        for(int i = 1;i <= n;i++){
            ans += abs(X1 - Xi[i]);
        }
        cout << ans << endl;
    }

    return 0;
}

/*
bug：1.M未置零
2.数学表达式不正确，Xi应该是从1到n（包含）而不是2到n-1（包含）
*/