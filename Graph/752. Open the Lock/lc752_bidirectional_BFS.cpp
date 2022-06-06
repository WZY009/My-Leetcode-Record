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
        // I don't care the traverse order, so queue is not very necessary!
        unordered_set<string> q1; // Starting Point
        unordered_set<string> q2; // Terminal Point
        unordered_set<string> visited;
        for(auto& deadend : deadends) dead.insert(deadend);
        if(dead.find("0000") != dead.end()) return -1;
        
        //queue<string> que;
        //que.push("0000");
        q1.insert("0000");
        q2.insert(target);
        
        int step = 0;
        while(!q1.empty() && !q2.empty()) {
            int size = q1.size();
            unordered_set<string> temp;
            for(string s : q1) {
                if(dead.find(s) != dead.end()) continue;
                if(q2.find(s) != q2.end()) return step;
                visited.insert(s);
                for(int j = 0; j < 4; j++) {
                    string up = upOne(s, j);
                    string down = downOne(s, j);
                    if(visited.find(up) == visited.end()) {
                        temp.insert(up);
                    }
                    if(visited.find(down) == visited.end()) {
                        temp.insert(down);
                    }
                }
            }
            q1 = q2;
            q2 = temp;
            step++;
        }
        return -1;
    }
};