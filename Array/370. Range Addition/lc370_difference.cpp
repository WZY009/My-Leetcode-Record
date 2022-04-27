// 2022 4.27 21：05
// 2022 4.27 21：17 Time Limit Exceeded!
class Difference{
public:
    vector<int> diff;
    Difference(vector<int>& nums) { // pay attention! It is better to use nums as parameter!
        diff = vector<int>(nums.size());
        diff[0] = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }
    Difference(int length) { // It can avoid creating extra array, which can improve the performance in this question, but it should not be a good method;
        diff = vector<int>(length, 0);
    }
    void operation(int left, int right, int val) {
        diff[left] += val;
        if(right + 1 < diff.size()) diff[right + 1] -= val;
    }
    void integral() {
        for(int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
        }
    }
};
class Solution {
public:
    vector<int> result;
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        Difference* Diff = new Difference(length);
        for(int i = 0; i < updates.size(); i++) {
            Diff->operation(updates[i][0], updates[i][1], updates[i][2]);
        }
        Diff->integral();
        return Diff->diff;
    }
};