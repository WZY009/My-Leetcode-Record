class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int start) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        else {
            for (int i = start; i <= n - (k - path.size()) + 1; i++) {
                path.push_back(i);
                backtracking(n, k, i + 1);
                path.pop_back(); // recall
            }

        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};