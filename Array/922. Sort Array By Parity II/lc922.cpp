class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(i % 2 == 0) {
                if(nums[i] % 2 == 0) continue;
                else {
                    for(int j = i + 1; j < nums.size(); j++) {
                        if(nums[j] % 2 == 0) {
                            swap(nums[i], nums[j]);
                            break;
                        }
                    }
                }
            }
            else {
                if(nums[i] % 2 == 1) continue;
                else {
                    for(int j = i + 1; j < nums.size(); j++) {
                        if(nums[j] % 2 == 1) {
                            swap(nums[i], nums[j]);
                            break;
                        }
                    }                    
                }
            }
        }
        return nums;
    }
};