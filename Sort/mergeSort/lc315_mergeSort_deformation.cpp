// 2022 5.20 20:00
// 2022 5.20 23：28 - viewing the answer 
class Solution {
public:
    vector<pair<int, int>> temp; // temporary array
    vector<int> count;
    
    void sort(vector<pair<int, int>>& arr, int begin, int end) {
        if(begin == end) return;
        int mid = begin + ((end - begin) >> 1);
        sort(arr, begin, mid);
        sort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
    
    void merge(vector<pair<int, int>>& arr, int begin, int mid, int end) {
        for(int i = begin; i <= end; i++) {
            temp[i] = arr[i];
        }
        int p1 = begin;
        int p2 = mid + 1;
        for(int i = begin; i <= end; i++) {
            if(p1 == mid + 1) arr[i] = temp[p2++];
            else if(p2 == end + 1) {
                arr[i] = temp[p1++];
                count[arr[i].second] += p2 - mid - 1;
            }
            else if(temp[p1] > temp[p2]) {
                arr[i] = temp[p2++];  
            }
            else {
                arr[i] = temp[p1++];
                count[arr[i].second] += p2 - mid - 1;                
            }
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int length = nums.size();
        temp = vector<pair<int, int>>(length);
        count = vector<int>(length);
        vector<pair<int, int>> arr(length);
        for(int i = 0; i < length; i++) arr[i] = {nums[i], i};
        sort(arr, 0, length - 1);
        return count;
    }
};