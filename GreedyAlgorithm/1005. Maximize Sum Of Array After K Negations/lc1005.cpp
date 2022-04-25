// although this problem is not very difficult to slove but I can't work it out still, sad
struct myClass{
    bool operator() (int a, int b) {
        return abs(a) > abs(b);
    }
}compare;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int result = 0;
        sort(nums.begin(), nums.end(), compare);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if(k % 2 == 1) nums[nums.size() - 1] *= -1;
        for(int i : nums) {
            result += i;
        }
        return result;
    }
};