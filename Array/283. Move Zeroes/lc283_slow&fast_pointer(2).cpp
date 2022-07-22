// 2022 4.30 16：27
// 2022 4.30 16:31 dual pointers


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        while(slow < nums.size()) {
            if(nums[slow] == 0) break;
            slow++;
        }
        int fast = slow + 1;
        while(fast < nums.size()) {
            if(nums[fast] == 0) fast++;
            else {
                swap(nums[fast], nums[slow]);
                fast++;
                slow++;
            }
        }
    }
};