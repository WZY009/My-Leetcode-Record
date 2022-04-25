class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < length; j++)//pay attention, you shold start with j+1, but not j!because it's unable to move the last result!
                    nums[j - 1] = nums[j];
                i--;
                length--;
            }
        }
        return length;
    }
};
