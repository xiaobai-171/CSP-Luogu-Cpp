/*
算法题中vector使用的很多，写下这篇文章加深掌握。
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec(10);
    /*初始化大小*/
    vector<int> vec2{0,1,2,3,4,5,6,7,8,9};
    cout << vec2[3] << endl;
    /*列表初始化*/
    vector<int>::iterator it = vec2.begin();
    /*对应的迭代器*/
    for(;it != vec2.end();it++){
        cout << *it << endl;
    }
    /*begin(),end(),【rbegin(),rend()反向迭代器】*/
    for(auto it = vec2.begin();it != vec2.end();it++){
        *it = 1;
        cout << *it << endl;
    }
    /*cbegin,cend 不可改变元素*/        

    system("pause");
    return 0;
}