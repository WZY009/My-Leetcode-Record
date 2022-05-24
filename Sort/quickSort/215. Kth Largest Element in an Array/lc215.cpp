// 2022 5.23 17:40 - You have to use quicksort!!!
class Solution {
public:
    void shuffle(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int randNum = i + rand() % (nums.size() - i);
            swap(nums[i], nums[randNum]);
        }
    }
    void sort(vector<int>& nums, int begin, int end) {
        if(begin >= end) return;
        int i = partition(nums, begin, end);
        sort(nums, begin, i - 1);
        sort(nums, i + 1, end);
    }
    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        int i = lo + 1;
        int j = hi;
        while(i <= j) {
            while(i < hi && nums[i] <= pivot) i++;
            while(j > lo && nums[j] > pivot) j--;
            if(i >= j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        shuffle(nums);
        sort(nums, 0, nums.size() - 1);
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(k == 1) return nums[i];
            k--;
        }
        return -1;
    }
};