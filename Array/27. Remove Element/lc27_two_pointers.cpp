// 2022 4.30 16：10
// 2022 4.30 16：25 一气呵成
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        while(slow < nums.size()) {
            if(nums[slow] == val) break;
            slow++;
        }
        if(slow == nums.size()) return slow;
        int fast = slow + 1;
        while(fast < nums.size()) {
            if(nums[fast] == val) fast++;
            else {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};