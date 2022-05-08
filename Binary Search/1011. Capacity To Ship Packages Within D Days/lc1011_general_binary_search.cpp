// 2022 5.6  9：37
// 2022 5.6 10:07 
// At first, I use a wrong method to deal with this problem, so I waste nearly 20 minutes. In fact, this question is similar to Koko eats banana
class Solution {
public:
    int getHours(vector<int>& weights, int capacity) {
        int cost = 0;
        int curCap = capacity;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] <= curCap) {
                curCap -= weights[i];
            }
            else {
                cost++;
                curCap = capacity;
                i--; // backtracking!
            }
        }
        return cost + 1; // the last one will not be calculated!
    }
    
    int left_bound(vector<int>& weights, int minCap, int maxCap, int target) {
        int left = minCap;
        int right = maxCap;
        int mid;
        while(left <= right) {
            mid = left + ((right - left) >> 1);
            int temp = getHours(weights, mid);
            if(temp == target) right = mid - 1;
            else if(temp < target) right = mid - 1;
            else if(temp > target) left = mid + 1;
        }
        return left;            
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCap = 0;
        int minCap = 1;
        for(int weight : weights) {
            maxCap += weight;
            minCap = minCap > weight ? minCap : weight;
        } 
        return left_bound(weights, minCap, maxCap, days);
    }
};