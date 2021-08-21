/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        for(int i = 0;i < nums.size();i++){
            auto temp = hashtable.find(target - nums[i]);
            if(temp != hashtable.end())
                return {temp->second, i};
            hashtable[nums[i]] = i;
        }
        return {-1};
    }
};

int main(){
    return 0;
}

/*
可以将搜索的复杂度降低到O(1)。使用unordered_map即可。
map也能降低，但是只能到log(n)。
因为，map是红黑树搜索，而unordered_map是散列表。
两者的区别详见：https://www.cnblogs.com/yimeixiaobai1314/p/14375195.html
结论：在需要元素有序性或者对单次查询性能要求较为敏感时，请使用map，其余情况下应使用unordered_map。
      因此在需要使用字典结构进行算法编程的大部分情况下，都需要使用unordered_map而不是map。
*/
/*另外，这里的思路是顺序遍历过去，从map里找，找到了直接返回，没有找到就把当前的添加到map中。
*/
