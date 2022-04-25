class Solution {
public:
    // The stock is only buy one time and sell out one time. Thus, you can find the lowest value left by i. Pay attention! you don't need find a maximum right by i! because it will let this algorithm degenerate to Brutal Force
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int result = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(low > prices[i]) low = prices[i];
            result = max(result, prices[i] - low);
        }
        return result;
    }
};