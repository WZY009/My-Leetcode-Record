class Solution {
public:
    int find(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) return i;
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = find(nums2, nums1[i]) + 1; j < nums2.size(); j++) {
                if (j == nums2.size() - 1 && nums2[j] <= nums1[i]) break;
                if (nums2[j] > nums1[i]){
                    result[i] = nums2[j];
                    break;
                }                 
            }
        }
        return result;
    }
};