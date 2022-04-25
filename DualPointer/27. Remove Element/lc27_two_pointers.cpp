class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (val != nums[fast])
                nums[slow++] = nums[fast];//pay attention! i++ means returning the value of i first, then go on increment.
        }
        return slow;
    }
};
