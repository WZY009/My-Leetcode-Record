class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> vec;
        int upper_bound = 0;
        int lower_bound = m - 1;
        int left_bound = 0;
        int right_bound = n - 1;
        while(vec.size() < m * n) {
            if(upper_bound <= lower_bound) {
                for(int j = left_bound; j <= right_bound; j++) {
                    vec.push_back(matrix[upper_bound][j]);
                }
                upper_bound++;
            }
            if(right_bound >= left_bound) {
                for(int j = upper_bound; j <= lower_bound; j++) {
                    vec.push_back(matrix[j][right_bound]);
                }
                right_bound--;
            }
            if(lower_bound >= upper_bound) {
                for(int j = right_bound; j >= left_bound; j--) {
                    vec.push_back(matrix[lower_bound][j]);
                }
                lower_bound--;
            }
            if(left_bound <= right_bound) {
                for(int j = lower_bound; j >= upper_bound; j--) {
                    vec.push_back(matrix[j][left_bound]);
                }
                left_bound++;                
            }
        }
        return vec;
    }
};