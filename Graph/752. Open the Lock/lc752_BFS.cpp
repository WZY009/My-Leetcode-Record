class Solution {
public:
    string upOne(string s, int j) {
        if(s[j] == '9' ) s[j] = '0';
        else s[j]++;
        return s;
    }
    string downOne(string s, int j) {
        if(s[j] == '0' ) s[j] = '9';
        else s[j]--;
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(auto& deadend : deadends) dead.insert(deadend);
        if(dead.find("0000") != dead.end()) return -1;
        unordered_set<string> visited;
        queue<string> que;
        que.push("0000");
        int step = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                string s = que.front();  que.pop();
                if(s == target) return step;
                for(int j = 0; j < 4; j++) {
                    string up = upOne(s, j);
                    string down = downOne(s, j);
                    if(dead.find(up) == dead.end() && visited.find(up) == visited.end()) {
                        visited.insert(up);
                        que.push(up);
                    }
                    if(dead.find(down) == dead.end() && visited.find(down) == visited.end()) {
                        visited.insert(down);
                        que.push(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};