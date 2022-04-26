class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        preSum = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    // pay attention to the boarder condition!
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */