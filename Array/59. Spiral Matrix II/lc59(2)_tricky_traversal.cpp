// 2022 5.1 15:10
// 2022 5.1 15:30 - 最后看了答案才修复中心取不到的bug（即n ^ 2 位置为0）
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n, 0));
        int upper_bound = 0;
        int lower_bound = n - 1;
        int left_bound = 0;
        int right_bound = n - 1;
        int k = 1;
        while(k <= n * n) { // pay attention! k can equal to n ^ 2
            if(upper_bound <= lower_bound) {
                for(int j = left_bound; j <= right_bound; j++) {
                    vec[upper_bound][j] = k++;
                }
                upper_bound++;
            }
            if(right_bound >= left_bound) {
                for(int i = upper_bound; i <= lower_bound; i++) {
                    vec[i][right_bound] = k++;
                }
                right_bound--;
            }
            if(lower_bound >= upper_bound) {
                for(int j = right_bound; j >= left_bound; j--) {
                    vec[lower_bound][j] = k++;
                }
                lower_bound--;                
            }
            if(left_bound <= right_bound) {
                for(int i = lower_bound; i >= upper_bound; i--) {
                    vec[i][left_bound] = k++;
                }
                left_bound++;
            }
        }
        return vec;
    }
};