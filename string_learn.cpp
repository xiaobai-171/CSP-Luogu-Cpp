/*
本篇关注算法题中常见的string函数，以及其他数据类型与string之间的转换。
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "this is a test string!";
    string s2 = "this is another test string!";

    /*截取一个string子串，并形成一个string--------------------------*/
    // 1：通过string构造函数实现。
    string str1(s,0,3);
    cout << "str1: " << str1 << endl;
    // 2：通过substr函数实现。
    string str2 = s.substr(0,3);
    
    /*字符串与各种数据类型的转换-----------------------------------*/
    /* 1.字符串转字符数组 */
    char p[20];
    strcpy(p,s.c_str());
    for(int i=0;i < strlen(p);i++){
        cout << p[i];
    }
    cout << "over！" << endl;
                /* 2.字符串转数字 */
                int i = stoi("2147483647");
                cout << "number: " << i << endl;
                /*不能超出范围，不然程序报错*/

                string number2 = "2147483648";
                int j = atoi(number2.c_str());
                cout << "number2: " << j << endl;
                /*超出范围会导致未定义的行为，目前这个例子是变成了-2147483648*/

                /* 3.数字转字符串-----------------------------------------------*/
                string numstr = to_string(-1233);
                cout << "数字转字符串 to_string: " << numstr << endl;
                /*to_string会将符号加进来*/

    /* 4.字符数组转数字 */
    char a[20];
    itoa(1234,a,10);
    int num = atoi(a);
    cout << "num: " << num << endl;

                /*string +号的妙用*/
                s += s2;
                cout << "s (again): " << s << endl;
                s += 'c';
                cout << "s (again2): " << s << endl;
                /*之后就放弃使用pop_back , push_back, append 这三个函数了*/

    system("pause");
    return 0;
}