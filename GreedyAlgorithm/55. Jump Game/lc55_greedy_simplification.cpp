class Solution {
public:
    bool canJump(vector<int>& nums) {
        int arrange = 0;
        if(nums.size() == 1) return true;
        for(int i = 0; i <= arrange; i++) {
            arrange = arrange > (i + nums[i]) ? arrange : (i + nums[i]);
            if(arrange >= nums.size() - 1) return true;
        }
        return false;
    }
};