#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string,int> mp;
    if(mp[""])
        cout << "有的" << endl;
    else   
        cout << "没有" << endl;

    string a = to_string(123) + "+" + to_string(345);
    cout << a; 

    mp.insert(make_pair(a,1));
    cout << mp[a];
    return 0;
}