class State {
public:
    int id;
    int distFromStart; // record the distance from start point.
    State(int id, int distFromStart) {
        this->id = id;
        this->distFromStart = distFromStart;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {        
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
        for(const vector<int>& time : times) {
            int from = time[0] - 1;
            int to = time[1] - 1;
            graph[from][to] = time[2];
        }
        vector<int> dist = dijkstra(k - 1, graph);
        int maximum = *max_element(dist.begin(), dist.end());
        return (maximum == INT_MAX) ? -1 : maximum;
    }
    vector<int> dijkstra(int start, const vector<vector<int>>& graph) {
        vector<int> dist(graph.size(), INT_MAX);
        dist[start] = 0;
        std::priority_queue<State*> pque;
        pque.push(new State(start, 0));
        while(!pque.empty()) {
            State* curState = pque.top(); pque.pop();
            if(curState->distFromStart - dist[curState->id] > 0) continue;
            for(int nextId = 0; nextId < graph.size(); nextId++) {
                if(nextId == curState->id || graph[curState->id][nextId] == INT_MAX) continue; // omit the node itself and the inaccessible nodes
                int distToNext = dist[curState->id] + graph[curState->id][nextId]; 
                if(dist[nextId] > distToNext) {
                    dist[nextId] = distToNext;
                    pque.push(new State(nextId, distToNext));
                }
            }
        }
        return dist;
    }
};