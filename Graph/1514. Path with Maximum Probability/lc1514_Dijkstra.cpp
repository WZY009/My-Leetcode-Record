// 2022 6.9 9:41(the time and space complexity can not be qualified!)
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < succProb.size(); i++) { // don't use adjacency matrix, or you will exceed the memory limit
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]); // Construct and insert element!!!
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        vector<double> prob(n, 0.0);
        priority_queue<pair<double, int>> pq;
        prob[start] = 1.0;
        pq.emplace(1.0, start); // push the starting point

        // Starting from the maximum probability point, find its adjacent edge
        while (!pq.empty()) {
            auto [p, u] = pq.top();pq.pop();
            if(u == end) break;
            if (p < prob[u]) continue; 
            for (auto [v, w] : graph[u]) { // updating the maximum probability of adjacent nodes from u
                if (prob[v] < prob[u] * w) {
                    prob[v] = prob[u] * w;
                    // pq.emplace(prob[v], v); // Construct and insert element, equals to the below:
                    pq.push({prob[v], v});
                }
            }
        }
        return prob[end];
    }
};