// 2022 5.21 15：30 ~ 15:43 (failed to slove)  
// 2022 5.21 16：00 (After viewing the answer)
class Solution {
public:
    int count = 0;
    vector<int> temp;
    
    void sort(vector<int>& nums, int begin, int end) {
        if(begin == end) return;
        int mid = begin + ((end - begin) >> 1); // use move bit!
        sort(nums, begin, mid);
        sort(nums, mid + 1, end);
        merge(nums, begin, mid, end);
    }
    
    void merge(vector<int>& nums, int begin, int mid, int end) {
        for(int i = begin; i <= end; i++) temp[i] = nums[i];
        
        int last = mid + 1; // you can use the initial situtation to check its border condition
        for(int i = begin; i <= mid; i++) {
            while(last <= end && (long long)nums[i] > (long long)nums[last] * 2) last++;
            count += last - (mid + 1);
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
    
    int reversePairs(vector<int>& nums) {
        temp = vector<int>(nums.size(), 0);
        sort(nums, 0, nums.size() - 1);
        return count;
    }
};
