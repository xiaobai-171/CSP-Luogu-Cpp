#include <iostream>
#include <algorithm>
using namespace std;

/*
题目：你有n个部下，每个部下需要完成一项任务。
第i个部下需要你花Bi分钟交待任务，然后他会立刻独立地、无间断地执行Ji分钟后完成任务。
你需要选择交代任务的顺序，使得所有任务尽早执行完毕（即最后一个执行完成的任务应尽早结束）。
注意，不能同时给两个部下交待任务，但部下们可以同时执行他们各自的任务。

输入格式：
输入包含多组数据，每组数据的第一行为部下的个数N（1<=N<=1000）；
以下N行每行两个正整数B和J（1<=B<=10 000，1<=J<=10 000），即交待任务的时间和执行任务的时间。
输入结束的标志为N=0。

输出格式：
对于每组数据，先输出“Case #: ”（‘#’表示第几组数据），然后是所有任务完成的最短时间。

样例输入：
3
2 5
3 2
2 1
3
3 3
4 4
5 5
0

样例输出：
Case 1：8
Case 2：15
*/

/*
这道题：贪心算法。直观上来看，完成时间长的应该先做。这是为什么呢？
完成时间 Ab + Aj
吩咐时间 Ab
执行时间 Aj
首先，A B两个活动是不影响其它活动的进行的，都是X - Ab - Bb或者X + Ab + Bb.
完成时间长的如果包含了完成时间短的，那么肯定先做，后坐的话要先等待完成时间短的先吩咐完毕，相当于
从 Ab + Aj -> Bb + Ab + Aj。
如果不包含的话，那么两个时间相当于(A在B的前面吩咐)
Ab + Bb + Bj ? Bb + Ab + Aj
所以，要Bj < Aj时间才更短。也就是说，执行时间长的放前面。
*/

struct Node{
    int b;
    int j;
};

bool cmp(Node node1,Node node2){
    // if(node1.j >= node2.j)
    //     return true;
    // else  
    //     return false;
    return node1.j >= node2.j;
}

int main(){
    int n,kcase = 1;
    while(cin >> n && n){
        Node node[n];
        int ans = 0,ins = 0;
        for(int i = 0;i < n;i++){
            cin >> node[i].b >> node[i].j;
        }
        sort(node,node+n,cmp);
        // for(int i = 0;i < n;i++){
        //     cout << node[i].j << " ";
        // }
        // cout << endl;
        for(int i = 0;i < n;i++){
            ins += node[i].b;
            ans = max(ans, ins+node[i].j);
        }
        cout << "Case " << kcase++ << ": " << ans << endl;

    }

    return 0;
}