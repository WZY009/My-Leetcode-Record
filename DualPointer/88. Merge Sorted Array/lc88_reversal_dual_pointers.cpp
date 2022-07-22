// 2022 5.20 21:06 ~ 21:17(sloved)
// 2022 5.20 21：44 - viewing the better one 
// 2022 5.20 21：53 - Sloved
 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;  
        int cur;
        while(tail >= 0) {
            if(p1 == -1) cur = nums2[p2--];
            else if(p2 == -1) cur = nums1[p1--];
            else if(nums1[p1] > nums2[p2]) cur = nums1[p1--];
            else cur = nums2[p2--];
            nums1[tail--] = cur;
        }
    }
};