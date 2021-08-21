#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,char> map = {{1,'a'}, {2,'b'}, {3, 'c'}, {1,'d'}};
    auto itr = map.equal_range(1);
    for(auto it = itr.first;it != itr.second;it++){
        cout << it->second << " ";
    }
    /*返回的是两个迭代器，一个上限，一个下限。
    /*结果依旧是a，不是d*/
    /*equal_range 函数对于map而言和find差不多功能，因为map键是唯一的。他对于unordered_multimap是有意义的。
    但是结果是无序的。*/
    cout << endl;
    long long a = map.max_size() + 1;
    cout << a << endl;
    int ans = 0;
    while(a > 1){
        a /= 2;
        cout << "a : " << a << endl;
        ans++;
    }
    cout << ans << endl;
    /*没啥用，看看就好*/
    auto tmp = map.emplace(1, 'e');
    cout << tmp.first->second << endl;
    cout << "bool: " << tmp.second << endl;
    /*
    emplace 是有就直接插入，没有不动。
    emplace 效率比insert高，因为insert是先创建pair再复制过去。而emplace是直接弄上去的。

    该方法的返回值为 pair 类型值，其包含一个迭代器和一个 bool 类型值：
    当 emplace() 成功添加新键值对时，返回的迭代器指向新添加的键值对，bool 值为 True；
    当 emplace() 添加新键值对失败时，说明容器中本就包含一个键相等的键值对，
    此时返回的迭代器指向的就是容器中键相同的这个键值对，bool 值为 False。
    */

    unordered_map<int,char>::iterator it;
    /*unordered_map 的迭代器*/

    map.erase(map.begin());
    /*返回一个指向被删除键值对之后位置的迭代器*/
    for(auto itr = map.begin();itr != map.end();itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    map.erase(1);
    /*该方法会返回一个整数，其表示成功删除的键值对的数量*/
    map.erase(map.begin(),map.end());
    /*该方法会返回一个指向被删除的最后一个键值对之后一个位置的迭代器。*/
    /*erase 删除的三种用法*/

    map.emplace(1,'1');
    map.emplace(2,'2');
    map.emplace(3,'3');
    map.emplace(4,'4');
    auto tmp2 = map.find(1);
    cout << "find 1: " << tmp2->second << endl;
    /*没有找到find返回的是end()*/
    /*这个函数返回的是对应位置的迭代器*/

    map[1] = '11';
    /*修改直接改*/

    /*增删查改完毕*/
    /*返回值除了emplace是pair类型，第一个是迭代器，第二个是bool结果，
    其他的是全部是迭代器，直接itr->first，itr->second。*/

    system("pause");

    return 0;
}