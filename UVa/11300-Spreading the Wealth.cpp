#include <iostream>
#include <algorithm>
#define MAX 1000010
using namespace std;

long long Xi[MAX];
long long A[MAX];
long long M;

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        long long ans = 0;
        M = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d", &A[i]);
            M += A[i];
        }
        M /= n;
        Xi[1] = 0;
        for(int i = 2;i <= n;i++){
            Xi[i] = Xi[i-1] + M - A[i-1]; 
        }
        sort(Xi+1,Xi+n+1);
        long long X1 = (Xi[(n+1)/2] + Xi[(n+1)/2]) / 2;
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
3.求Xi的方法太笨了，开销会很大的，别懒。
*/