// 2022 6.4 21:55(After viewing the answer) ~ 22:08

class Solution {
public:
    vector<bool> visited;
    vector<bool> path;
    vector<list<int>> graph;
    bool hasCircle = false;
    vector<int> res;
    vector<list<int>> createGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<list<int>>(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            graph[from].push_back(to);
        }
        return graph;
    }
    void traverse(int node) {
        if(path[node]) {
            hasCircle = true;
            return;
        }
        if(visited[node] || hasCircle) return;
        path[node] = true;
        visited[node] = true;
        for(int next : graph[node]) {
            traverse(next);
        }
        res.push_back(node);
        path[node] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        createGraph(numCourses, prerequisites);
        visited = vector<bool>(numCourses, false);
        path = vector<bool>(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            traverse(i);
        }
        if(hasCircle) return vector<int>();
        reverse(res.begin(), res.end());
        return res;
    }
};