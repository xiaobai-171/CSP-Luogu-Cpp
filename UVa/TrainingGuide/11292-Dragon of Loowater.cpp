#include <iostream>
#include <algorithm>
#define MAX 20005
using namespace std;

int A[MAX];
int B[MAX];

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