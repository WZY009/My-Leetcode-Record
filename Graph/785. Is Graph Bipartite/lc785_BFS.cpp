// BFS 
class Solution {
public:
    bool* visited;
    bool* color;
    bool isBiGraph = true;
    
    bool isBipartite(vector<vector<int>>& graph) {
        int length = graph.size();
        visited = new bool[length];
        memset(visited, false, length);
        color = new bool[length];
        memset(color, true, length); // Pay attention! You have to initalize the bool array if you use dynamic array way
        for(int v = 0; v < length; v++) {
            if(!visited[v]) traverse(graph, v);
        }
        return isBiGraph;
    }
    
    void traverse(vector<vector<int>>& graph, int node) {
        queue<int> que;
        que.push(node);
        while(!que.empty() && isBiGraph) {
            int curV = que.front(); que.pop();
            visited[curV] = true;
            for(int v : graph[curV]) {
                if(!visited[v]) {
                    color[v] = !color[curV];
                    que.push(v);
                } else {
                    if(color[v] == color[curV]) {
                        isBiGraph = false;
                        return;
                    }
                }
            }

        }
    }
};