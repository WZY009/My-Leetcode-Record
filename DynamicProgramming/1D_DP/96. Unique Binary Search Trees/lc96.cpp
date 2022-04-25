/*
analysis:
    1. confirm what is dp: 
        dp[i] means from 1 to i, the number of structurally unique BST
    2. confirm Recurrence formula:
        select j as root (1 <= j <= i) to see what happens, the number of this kind of BST is the number of right child nutiples the number of left child. Because of BST's properties, the number of right child's node is (i - j) and the number of left child's node is (j - 1). Thus, dp[i] = ∑ dp[j - 1] * dp[i - 1]
    3. initialize the dp:
         If you initialize dp[0] = 0, the number of one-side BST is 0. It is impossible so you should initialize it as 1!
    4. confirm the traversal order:
        Absolutely, you should travere dp from front to end.
        
    
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j]; 
            }
        }
        return dp[n];       
    }
};