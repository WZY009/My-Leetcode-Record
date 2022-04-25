// solution 1 -- BF
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int peek = arr[0];
        int pos = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(peek < arr[i]) {
                peek = arr[i];        
                pos = i;                
            }
        }
        if(pos == arr.size() - 1 or pos == 0) return false;
        for(int i = 1; i < pos; i++) {
            if(arr[i] <= arr[i - 1] or arr[i] >= peek) return false;
        }
        for(int i = pos + 1; i < arr.size(); i++) {
            if(arr[i] >= arr[i - 1] or arr[i] >= peek) return false; 
        } 
        return true;
    }
};