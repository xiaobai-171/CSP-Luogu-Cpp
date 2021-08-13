#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int b;
    int j;
};

bool cmp(Node node1,Node node2){
    if(node1.j >= node2.j)
        return true;
    else   
        return false;
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
        for(int i = 0;i < n;i++){
            ins += node[i].b;
            ans = max(ans, ins+node[i].j);
        }
        cout << "Case " << kcase++ << ": " << ans << endl;

    }

    return 0;
}