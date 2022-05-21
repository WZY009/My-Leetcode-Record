// 2022 5.21 16:30 ~ 16:38 (can't slove it)
// 2022 5.21 17:13 - Viewing the answer, that's so amazing! 

class Solution {
public:
    int count;
    int low;
    int high;
    vector<long> temp;
    
    void sort(vector<long>& nums, int begin, int end) {
        if(begin == end) return;
        int mid = begin + ((end - begin) >> 1);
        sort(nums, begin, mid);
        sort(nums, mid + 1, end);
        merge(nums, begin, mid, end);
    }
    
    void merge(vector<long>& nums, int begin, int mid, int end) {
        for(int i = begin; i <= end; i++) temp[i] = nums[i];
        
        int l = mid + 1;
        int r = mid + 1;
        for(int i = begin; i <= mid; i++) { // Due to increasing array
            while(l <= end && nums[l] - nums[i] < low) l++;
            while(r <= end && nums[r] - nums[i] <= high) r++;
            count += r - l; // pay attention! At this time, r points to invalid number but l points to a valid number.
        }
        
        int p1 = begin;
        int p2 = mid + 1;
        for(int i = begin; i <= end; i++) {
            if(p1 == mid + 1) nums[i] = temp[p2++];
            else if(p2 == end + 1) nums[i] = temp[p1++];
            else if(temp[p1] > temp[p2]) nums[i] = temp[p2++];
            else nums[i] = temp[p1++];
        }
        
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        low = lower;
        high = upper;
        vector<long> preSum(nums.size() + 1, 0);
        for(int i = 1; i < preSum.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        temp = vector<long>(preSum.size(), 0);
        sort(preSum, 0, preSum.size() - 1);
        return count;
    }
};