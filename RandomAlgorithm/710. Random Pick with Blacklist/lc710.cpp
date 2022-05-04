// 2022 5.4 19:41 - view and understand the answer
// 2022 5.4 19:54 - pass but I review the tuition twice

class Solution {
public:
    int range;
    unordered_map<int, int> umap;
    
    Solution(int n, vector<int>& blacklist) {
        range = n - blacklist.size();
        for(int i : blacklist) umap[i]++;
        int last = n - 1;
        for(int i : blacklist) {
            if(i >= range) continue;
            while(umap.find(last) != umap.end()) 
                last--;         
            umap[i] = last;
            last--;
        }        
    }
    
    int pick() {
        int randNum = rand() % range;
        if(umap.find(randNum) != umap.end()) return umap[randNum];
        return randNum;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */