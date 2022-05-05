// 2022 5.5 11:20 - After knowing Fisher–Yates Shuffle Algorithm
// 2022 5.5 11:26
class Solution {
public:
    vector<int> vec;
    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    vector<int> reset() {
        return vec;
    }
    
    vector<int> shuffle() {
        vector<int> nums = vec;
        for(int i = 0; i < nums.size(); i++) {
            int randNum = i + rand() % (nums.size() - i);
            swap(nums[i], nums[randNum]);
        }
        return nums;        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */