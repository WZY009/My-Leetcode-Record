class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
         if(path.size() == nums.size())  {
             result.push_back(path);
             return;
         }
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue; // remove the duplicate in the same level!
            if(used[i] == false){ // prevent creating duplicate in the same branch
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;                
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
};