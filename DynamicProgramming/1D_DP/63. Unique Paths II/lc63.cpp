class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++)  vec[i][0] = 1;
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) vec[0][j] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) continue; // serve the obstacle as 0 ways to achieve!
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1]; 
            }
        }
        return vec[m - 1][n - 1];
    }
};