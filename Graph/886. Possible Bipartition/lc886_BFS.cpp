// 2022 6.8 23:26 - DFS
// I have to record this quesiton. There is a very implicit condition inside.
// If A dislikes B, B must dislike A. While, it may be very difficult to understand. In our daily life, the hate for a person might be one direction. But in this quesion, the hate must be bidirectional. If A dislike B, A and B can not be in the same group, so the graph should record bidirectional edges.

// 2022 6.8 23:56 - BFS ~ 2022 6.9 0:21

class Solution {
public:
    bool* visited;
    bool* color;
    bool isPossible = true;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        visited = new bool[n];
        memset(visited, false, n);
        color = new bool[n];
        memset(color, true, n);
        vector<vector<int>> graph = createGraph(dislikes, n);
        for(int i = 0; i < n; i++) {
            bfs(graph, i);
        }
        return isPossible;
    }
    void bfs(vector<vector<int>>& graph, int node) {
        queue<int> que;
        que.push(node);
        while(!que.empty() && isPossible) {
            int curV = que.front(); que.pop();
            for(int v : graph[curV]) {
                if(!visited[v]) {
                    visited[v] = true;
                    color[v] = !color[curV];
                    que.push(v);
                } else {
                    if(color[v] == color[curV]) {
                        isPossible = false;
                        return;
                    }
                }
            }
        }
    }
    vector<vector<int>> createGraph(vector<vector<int>>& edges, int n) {
        vector<vector<int>> vec(n);
        for(const vector<int>& edge : edges) {
            vec[edge[0] - 1].push_back(edge[1] - 1);
            vec[edge[1] - 1].push_back(edge[0] - 1);
        }
        return vec;
    }
};