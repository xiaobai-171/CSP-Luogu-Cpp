/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每 2k 个字符反转前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"
示例 2：

输入：s = "abcd", k = 2
输出："bacd"
 

提示：

1 <= s.length <= 104
s 仅由小写英文组成
1 <= k <= 104


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};

int main(){
    return 0;
}
/*
相比于下面我的解法，官方题解将题目理解的更加透彻。相当于是2k的窗口在平移，把前k个反转。
末尾时，把剩下的或者k个反转。
*/

/*
class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 0;
        int right = 2*k;
        bool flag = false;
        for(; ;left += 2*k,right += 2*k){
            if(right > s.length()){
                flag = true;
                if(s.length()-left < k){
                    reverse(s.begin()+left,s.end());
                }
                else{
                    reverse(s.begin()+left,s.begin()+left+k);
                }
            }
            else{
                reverse(s.begin()+left,s.begin()+left+k);
            }
            if(flag){
                break ;
            }
        }
        return s;
    }
};
*/