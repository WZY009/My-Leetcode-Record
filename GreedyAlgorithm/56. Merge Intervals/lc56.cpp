/*
the thinking of this problem is not very difficult, even if I do it firstly I can still work it out.
But it not very easy to complete it especially there are two loop!
*/
struct myClass{
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
}compare;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare);
        bool flag = false; // because you are not sure whether the last one can be merged or not
        for(int i = 1; i < intervals.size(); i++) {
            int start = intervals[i - 1][0];
            int end = intervals[i - 1][1];
            while(i < intervals.size() && intervals[i][0] <= end) {
                end = end > intervals[i][1] ? end : intervals[i][1];
                if(i == intervals.size() - 1) flag = true;
                i++;
            }
            result.push_back({start, end});
        }
        if(flag == false) result.push_back({intervals[intervals.size() - 1][0], intervals[intervals.size() - 1][1]});
        return result;       
    }
};