class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;        
        vector<int> vec(n + 1);
        vec[0] = 0;
        vec[1] = 1;
        for(int i = 2; i <= n; i++) {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        return vec[n];
    }
};
