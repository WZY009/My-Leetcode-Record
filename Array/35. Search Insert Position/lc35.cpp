class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //if(target > nums[nums.size() - 1]) return nums.size(); // it is not necessary!
        if (target < nums[0]) return 0;
        return getRightBorder(nums, target);
        
    }
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1;
        int rightBorder = -1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] > target) {
                right = mid - 1;
            }
            else if(nums[mid] == target) return mid;
            else {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
};