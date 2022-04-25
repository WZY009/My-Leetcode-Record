/*
需要注意的是：使用set去重的版本相对于used数组的版本效率都要低很多，大家在leetcode上提交，能明显发现。

原因在回溯算法：递增子序列中也分析过，主要是因为程序运行的时候对unordered_set 频繁的insert，unordered_set需要做哈希映射（也就是把key通过hash function映射为唯一的哈希值）相对费时间，而且insert的时候其底层的符号表也要做相应的扩充，也是费时的。

而使用used数组在时间复杂度上几乎没有额外负担！

使用set去重，不仅时间复杂度高了，空间复杂度也高了，在本周小结！（回溯算法系列三）中分析过，组合，子集，排列问题的空间复杂度都是$O(n)$，但如果使用set去重，空间复杂度就变成了$O(n^2)$，因为每一层递归都有一个set集合，系统栈空间是n，每一个空间都有set集合。

那有同学可能疑惑 用used数组也是占用$O(n)$的空间啊？

used数组可是全局变量，每层与每层之间公用一个used数组，所以空间复杂度是$O(n + n)$，最终空间复杂度还是$O(n)$。
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
         if(path.size() == nums.size())  {
             result.push_back(path);
             return;
         }
        unordered_set<int> uset; // using unordered_set to remove duplicate is not very efficient！
        for(int i = 0; i < nums.size(); i++) {
            if(uset.find(nums[i]) != uset.end() || used[i] == true) continue;
            used[i] = true;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};