class Solution {
public:
    vector<bool> visited;
    vector<bool> color;
    bool isBiGraph = true;
    
    bool isBipartite(vector<vector<int>>& graph) {
        visited = vector<bool>(graph.size(), false);
        color = vector<bool>(graph.size());
        for(int v = 0; v < graph.size(); v++) {
            if(!visited[v]) traverse(graph, v);
        }
        return isBiGraph;
    }
    
    void traverse(vector<vector<int>>& graph, int node) {
        if(!isBiGraph) return;
        
        visited[node] = true;
        for(int v : graph[node]) {
            if(!visited[v]) {
                color[v] = !color[node];
                traverse(graph, v);
            }
            else {
                if(color[v] == color[node]) {
                    isBiGraph = false;
                    return;
                }
            }
        }
    }
};