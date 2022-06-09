// pay attention! you can't use ordinary queue because of the validation condition in the exit! - You can go to 1514. Path with Maximum Probability to see futher details!

class State{
public:
    int x;
    int y;
    int effortFromStart;
    State(int x, int y, int effortFromStart) {
        this->x = x;
        this->y = y;
        this->effortFromStart = effortFromStart;
    }
};
struct cmp{
    bool operator()(State* s1, State* s2) {
        return s1->effortFromStart > s2->effortFromStart;
    }
};
class Solution {
public:
    
    // vector<vector<int>>
    vector<vector<int>> adjacency(vector<vector<int>>& heights, State& s) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
        int nx;
        int ny;        
        for(int i = 0; i < 4; i++) {
            switch(i) {
                case 0:
                    nx = s.x;
                    ny = s.y + 1;
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    res.push_back({nx, ny});
                    break;
                case 1:
                    nx = s.x - 1;
                    ny = s.y;
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    res.push_back({nx, ny});
                    break;  
                case 2:
                    nx = s.x + 1;
                    ny = s.y;
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    res.push_back({nx, ny});
                    break;   
                case 3:
                    nx = s.x;
                    ny = s.y - 1;
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    res.push_back({nx, ny});
                    break;                      
            }
        }
        return res;
    } 
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        // effortTo represents that the comsumption from (0, 0) to (i, j)
        vector<vector<int>> effortTo(m, vector<int>(n, INT_MAX));
        effortTo[0][0] = 0;
        priority_queue<State*, vector<State*>, cmp> pq; // it's very easy to make some mistakes!
        pq.push(new State(0, 0, 0));
        while(!pq.empty()) {

            State* curNode = pq.top(); pq.pop();
            
            if(curNode->x == m - 1 && curNode->y == n - 1) return curNode->effortFromStart; 
            
            if(curNode->effortFromStart > effortTo[curNode->x][curNode->y]) continue;
            vector<vector<int>> adj = adjacency(heights, *curNode);
            for(const auto& nextNode : adj) {
                int effortToNext = max(
                    effortTo[curNode->x][curNode->y], 
                    abs(heights[curNode->x][curNode->y] - heights[nextNode[0]][nextNode[1]])
                );
                if(effortToNext < effortTo[nextNode[0]][nextNode[1]]) {                  
                    effortTo[nextNode[0]][nextNode[1]] = effortToNext;
                    pq.push(new State(nextNode[0], nextNode[1], effortToNext));
                }
            }
        }
        return -1;
        
    }
};