class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    void backtracking(int k, int n, int startIndex) {
        if (path.size() == k && sum == n) {
            result.push_back(path);
            return;
        }
        else if (path.size() == k && sum != n) {
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) { // right-pruning cutting the brunches of deficit array number
            path.push_back(i);
            sum += i;
            backtracking(k, n, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if (k <= n)
            backtracking(k, n, 1);
        return result;
    }
};