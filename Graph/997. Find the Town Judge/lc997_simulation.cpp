class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> vec(n, {0, 0}); // the first represents the number of i is trusted by others, the second is the number of i trust others.
        for(int i = 0; i < trust.size(); i++) {
            vec[trust[i][1] - 1].first++;
            vec[trust[i][0] - 1].second = -1;
        }
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i].first == n - 1 && vec[i].second == 0) return i + 1;
        }
        return -1;
    }
};