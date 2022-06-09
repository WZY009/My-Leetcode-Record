class Solution {
public:

    int dist(vector<int>& a, vector<int>& b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        vector<int> mindist(n, 0);
        for(int i = 1; i < n; i++) {
            mindist[i] = dist(points[0], points[i]);
        }
        mindist[0] = 0;
        int cost = 0;
        for(int k = 0; k < n - 1; k++)
        {
            int pos = 0;
            int minn = INT_MAX;
            for(int i = 0; i < n; i++)
            {
                if(!visited[i] && minn > mindist[i])
                {
                    minn = mindist[i];
                    pos = i;
                }
            }
            cost += minn;
            visited[pos] = true;
            mindist[pos] = 0;
            for(int i = 0; i < n; i++) {
                if(!visited[i] && dist(points[pos], points[i]) < mindist[i])  mindist[i] = dist(points[pos], points[i]);
            }
        }
        return cost;
    }
};