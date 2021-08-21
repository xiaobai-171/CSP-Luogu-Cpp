/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 1,end = 1;
        int ans = 0;
        unordered_map<char,int> map;
        while(end <= s.length()) {
            if(map[s[end-1]]){//找到了
                start = max(map[s[end-1]]+1, start);
            }
            map[s[end-1]] = end;
            ans = max(ans, end-start+1);
            end++;
        }
        return ans;
    }
};

/*
一次迭代就可以完成。
每次迭代start可能因为重复字符串改变（max比较就是为了解决map前置的键值对重复判断的影响。
我们start之前的应该是被舍弃的字串，只有在start之后的才有意义。
说明在前面不能改变start的值），每次迭代判断一次ans结果。
*/