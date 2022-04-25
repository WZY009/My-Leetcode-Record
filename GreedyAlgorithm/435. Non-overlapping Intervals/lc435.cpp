struct myClass{
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // pay attention! there are huge difference between left and right sort!
    }
}compare;
class Solution {
public:
    int eraseOverlapIntervals (vector<vector<int>>& intervals) {
        sort (intervals.begin(), intervals.end(), compare);
        int result = 1;
        int end = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++) {
            if(end <= intervals[i][0]) {
                result++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - result;
    }
};