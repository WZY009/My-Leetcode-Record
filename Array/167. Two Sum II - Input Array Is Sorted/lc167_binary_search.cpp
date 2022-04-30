// 2022 4.30 16:34
// 2022 4.30 16:58 -- have two WA 
class Solution {
public:
    int find(vector<int>& nums, int start, int end, int target) {
        if(start > end) return -1;
        int mid = start + ((end - start) >> 1);
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return find(nums, mid + 1, end, target);
        else return find(nums, start, mid - 1, target);
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; i++) {
            int j = find(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
            if(j != -1) return { i + 1, j + 1 }; 
        }
        return {-1, -1};
    }
};