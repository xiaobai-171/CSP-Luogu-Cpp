#include <iostream>
#include <algorithm>
#define MAX 20005
using namespace std;

/*原题为：
王国里有一条 n 个头的恶龙，希望雇一些骑士砍掉它所有的头。
村中有 m 个骑士可以雇佣，一个能力值为 x 的骑士可以砍掉恶龙一个直径不超过 x 的头，且需支付 x 个金币。
如何雇佣骑士才能砍掉恶龙所有的头，且支付的金币最少？（一个骑士只能砍一个头，且只能被雇佣一次）

[输入格式] 第一行输入正整数 n,m，m 代表村中骑士的数量，n 代表龙的头数。
第二行到第 n+1 行输入的数据为龙每一个头的直径，第 n+2 行往后 m 个数据为每个骑士的能力。

[输出格式] 对于每组数据，输出最少花费，若无解，则输出 “Loowater is doomed!”。

【样例输入】
2 3
5
4
7
8
4
2 1
5
5
10
0 0

【样例输出】
11
Loowater is doomed!

*/

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