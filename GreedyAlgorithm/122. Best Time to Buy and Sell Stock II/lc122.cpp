class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Greedy method: adding all postitive difference
        int result = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - prices[i - 1] > 0) result += prices[i] - prices[i - 1];
        }
        return result;
    }
};