struct myClass{
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
}compare;
// although this problem is not very difficult to slove but it is quite hard to complete it by myself
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int result = 1;
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > points[i - 1][1]) result++;
            else 
                //points[i][1] = points[i - 1][1]; // I don't consider the situation that when points[i] is a subset of points[i - 1]
                points[i][1] = min(points[i][1], points[i - 1][1]);
        }
        return result;
    }
};