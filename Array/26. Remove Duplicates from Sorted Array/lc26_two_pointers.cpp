// 2022 4.30 15：52
// 2022 4.30 15：58 -- 一气呵成
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int slow = 0;
        int fast = 1;
        while(fast < nums.size()) {
            if(nums[fast] != nums[slow]) {
                swap(nums[fast], nums[slow + 1]);
                fast++;
                slow++;
            }
            else {
                fast++;
            }
        }
        return slow + 1;
    }
};