class Solution {
public:
    bool canJump(vector<int>& nums) {
        int arrange = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(arrange >= nums.size() - 1) return true;
            if(nums[i] != 0) { // all the failure situation will converge to nums[i] == 0!
                arrange = arrange > (i + nums[i]) ? arrange : (i + nums[i]);                
            }
            else if(arrange == i)  return false; // arrange will be larger or equal to i
            else continue;            
        }
        return true;
    }
};