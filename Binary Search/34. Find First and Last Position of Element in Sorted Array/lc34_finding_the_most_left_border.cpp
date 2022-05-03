class Solution {
public:
    int left_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;
        while(left <= right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] == target) {
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        if(left >= nums.size() || nums[left] != target) return -1; // pay attention! the validation condition can not be reversed!!!! Or it will make mistake! Check whether it will overflow the array is the most important one!
        return left;
    }
    int right_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;    
        while(left <= right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] == target) {
                left = mid + 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }            
        }
        if(right < 0 || nums[right] != target) return -1;
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        vector<int> vec(2, -1);
        vec[0] = left_bound(nums, target);
        vec[1] = right_bound(nums, target);
        return vec;
    }
};