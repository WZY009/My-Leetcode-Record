class Solution {
    // the most important point is how to remove duplicate indexes
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return result;
            // if(nums[i] == nums[i + 1]) continue; // it is wrong! because you will make mistake when the example is  [-1, -1, 2]
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
     
            int right = nums.size() - 1;
            while (right > left) {
                //the following two rows should not be here because it will ignore the [0, 0, 0]
                // while(right > left && nums[left] == nums[left + 1]) left++;
                // while(right > left && nums[right] == nums[right - 1]) right--;
                if (nums[right] + nums[left] + nums[i] < 0) left++;
                // pay attention! this row can not use if because when left++, it should be examinate the duplicate
                else if (nums[right] + nums[left] + nums[i] > 0) right--;
                else {
                    result.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    // you have to remove duplicate before finding triplet
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};
