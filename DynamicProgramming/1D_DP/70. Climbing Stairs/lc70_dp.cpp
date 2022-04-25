class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> vec(n + 1);
        vec[1] = 1;
        vec[2] = 2;        
        for(int i = 3; i <= n; i++) {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        return vec[n];
    }
};