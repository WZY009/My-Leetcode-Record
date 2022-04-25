class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> hash(2001, 0);       
        for(int i = 0; i < arr.size(); i++) {
            hash[arr[i] + 1000]++;
        }
        sort(hash.begin(), hash.end());
        for(int i = 1999; i >= 0; i--) {
            if(hash[i] == 0) break;
            if(hash[i] == hash[i + 1]) return false;
        }
        return true;
    }
};