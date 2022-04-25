class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // the main idea is setting off from the 0 index, and then find the hardest condition --- if you drive from i - 1 to i, the left of gas tank become minus, which means you have to get enough gas before i. Thus, searching for a starting point that can provide you with enough gas is necessary.
        int curSum = 0;
        int min = INT_MAX;
        int distance = gas.size();
        for(int i = 0; i < distance; i++) {
            curSum += gas[i] - cost[i];
            if(curSum < min) {
                min = curSum;
            }
        }
        if(curSum < 0) return -1; // the overall gas volume is less than you need, you can't arrive absolutely!
        if(min >= 0) return 0; // if you set off from the 0 index, the hardest time can still overcome;
        for(int i = distance - 1; i > 0; i--) {
            min += gas[i] - cost[i];
            if(min >= 0) return i;
        }
        return -1;
    }
};
