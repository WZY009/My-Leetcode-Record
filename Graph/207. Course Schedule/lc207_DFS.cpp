// 2022 6.4 17：27 ~ 17：40 - Go to view the answer although I know I should use the algorithm of checking enclosed circle
// 2022 6.4 20:41 ~ 21:04

class Solution {
public:
    bool isCircle = false;
    vector<bool> visited;
    vector<bool> path;
    vector<list<int>> createGraph(const vector<vector<int>>& prerequisites, int num) {
        vector<list<int>> graph(num);
        for(int i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            graph[from].push_back(to);
        }
        return graph;
    }
    void traverse(const vector<list<int>>& graph, int node) {
        if(path[node]) {
            isCircle = true;
            return;
        }
        if(visited[node]) return;
        visited[node] = true;
        path[node] = true;
        for(int next : graph[node]) {
            traverse(graph, next);
        }
        path[node] = false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        path = vector<bool>(numCourses, false);
        vector<list<int>> graph = createGraph(prerequisites, numCourses);
        for(int i = 0; i < numCourses; i++) {
            traverse(graph, i);
        }
        return !isCircle;
    }
};