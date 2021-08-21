#include <iostream>
#include <cmath>
using namespace std;

int countDigitOne(int n) {
    int ans = 0;
    long long k = 1;
    while(k <= n){
        ans += fmin(fmax(0LL, n % (k * 10) - k + 1), k);
        ans += n / (k*10) * k; 
        k *= 10;
    }
    
    return ans;
}

int main(){
    cout << countDigitOne(2000000000);
    system("pause");
}

