// 2022 6.5 14:55 
// The key work is to know how to swap move the position.
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        const string target = "123450";
        string start;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
                start += to_string(board[i][j]);
        }
        // this array record the neighbor index in the flatten two-dimensonal array
        vector<vector<int>> neighbor = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}
        };
        queue<string> que;
        unordered_set<string> visited;
        que.push(start);
        visited.insert(start);
        int step = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                string s = que.front(); que.pop();
                if(s == target) return step;
                int j = 0; // j represents the index of flatten array
                while(s[j] != '0') j++;
                for(int index : neighbor[j]) {
                    string next = s;
                    swap(next[j], next[index]);
                    if(visited.find(next) == visited.end()) {
                        que.push(next);
                        visited.insert(next);
                    }
                }
            }
            step++;
        }
        return -1;
        
    }
};