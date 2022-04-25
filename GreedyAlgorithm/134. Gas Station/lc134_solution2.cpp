class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // local optimum  : if the sum of gas[i] - cost[i] is minus, the starting index must be larger than i!
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(curSum < 0) {
                start = (i + 1) % gas.size();
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
};