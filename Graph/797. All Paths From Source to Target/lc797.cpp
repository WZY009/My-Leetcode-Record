// 2022 5.26 19:46 - After viewing the answer
// 2022 5.26 19:53 - Reviewing the answer for one time
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void DFS(const vector<vector<int>> &graph, int start)
    {
        if (start == graph.size() - 1)
        {
            res.push_back(path);
            return;
        }
        for (auto &y : graph[start])
        {
            path.push_back(y);
            DFS(graph, y);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        path.push_back(0);
        DFS(graph, 0);
        return res;
    }
};