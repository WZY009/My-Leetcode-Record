class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector(n, 0)); // you have to initialize the matrix first! Or you can't operate the matrix
        int offset = 1; // the first time of spiring, you should only run for only (n - 1) times. The offset is used to measure the runing times of each side
        int startX = 0, startY = 0; // These two indexes measure the starting points
        int count = 1;
        int mid = n / 2;
        int loop = n / 2; //define the times of loop！！！
        while (loop > 0) {
            loop--;
            int i = startX, j = startY;
            for (; j < startY + n - offset; j++)
                result[i][j] = count++;
            for (; i < startX + n - offset; i++)
                result[i][j] = count++;
            for (; j > startY; j--)
                result[i][j] = count++;
            for (; i > startX; i--)
                result[i][j] = count++;
            startX++;
            startY++;
            offset += 2;
        }
        if (n % 2 != 0)
            result[mid][mid] = count;
        return result;
    }
};