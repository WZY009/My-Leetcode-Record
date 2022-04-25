class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int hash[2001] = {0};       
        for(int i = 0; i < arr.size(); i++) {
            hash[arr[i] + 1000]++;
        }
        bool frequence[1001] = {false};
        for(int i = 0; i < 2001; i++) {
            if(hash[i] != 0) {
                if(!frequence[hash[i]]) {
                    frequence[hash[i]] = true;
                }
                else return false;
            }
        }
        return true;
    }
};