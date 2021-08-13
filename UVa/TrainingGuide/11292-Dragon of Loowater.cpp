#include <iostream>
#include <algorithm>
#define MAX 20005
using namespace std;

int A[MAX];
int B[MAX];

int main(){
    int n,m;
    while(cin >> n >> m && (n || m) ){
        int k = 0;
        int ans = 0;
        for(int i=0;i < n;i++){ cin >> A[i]; }
        for(int j=0;j < m;j++){ cin >> B[j]; }
        sort(A,A+n);
        sort(B,B+m);
        //注意不要用最下面的以头为标准的解法，麻烦了
        for(int j = 0;j < m;j++){//对于每一个勇士
            if(k < n && B[j] >= A[k]){//头没砍完且能砍  就砍
                k++;
                ans += B[j];
            }
        }
        if(k != n){ cout << "Loowater is doomed!" << endl; }
        else { cout << ans << endl; }
    }

    return 0;
}
/*
int main(){
    int n,m;
    while(cin >> n >> m && n && m){
        int sum = 0;
        bool flag = true;
        for(int i = 0;i < n;i++){ cin >> A[i]; }
        for(int i = 0;i < m;i++){ cin >> B[i]; }
        sort(A,A+n);
        sort(B,B+m);
        int j = 0;
        for(int i=0;i < n;i++){
            int temp = A[i];
            while(B[j] < temp && j < m){
                j++;
            }
            if(j == m){
                flag = false;
                break ;
            }
            else{
                sum += B[j];
                j++;
            }
        }
        if(flag){
            cout << sum << endl;
        }
        else{
            cout << "Loowater is doomed!" << endl;
        }
    }
    system("pause");

    return 0;
}
*/