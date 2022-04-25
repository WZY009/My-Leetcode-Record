class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int pathSum = 0;

    void backtracking(vector<int>& candidates, int target, int startIndex) {
        if (pathSum > target) return;
        else if (pathSum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && (pathSum + candidates[i] <= target); i++) { // right pruning, but you have to sort the array first!
            path.push_back(candidates[i]);
            pathSum += candidates[i];
            backtracking(candidates, target, i);
            pathSum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }

};