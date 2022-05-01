// 2022 5.1 14:00
// 2022 5.1 14:19 - 会者不难，难者不会 - tricky traversal
class Solution {
public:
    void reverse(vector<int>& vec) {
        for(int i = 0, j = vec.size() - 1; i < j; i++, j--) {
            swap(vec[i], vec[j]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            reverse(matrix[i]);
        }
    }
};