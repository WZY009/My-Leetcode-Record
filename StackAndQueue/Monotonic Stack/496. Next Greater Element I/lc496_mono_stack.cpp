class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result (nums1.size(), -1);
        stack<int> st;
        st.push (0);
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i;
        }
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] <= nums2[st.top()]) {
                st.push(i);
            }
            else {
                while(!st.empty() && nums2[i] > nums2[st.top()]) {
                    if(umap.find(nums2[st.top()]) != umap.end()) { // if there is nums2[st.top()] in the nums1, the nums2[st.top()] should be cast away!
                        int index = umap[nums2[st.top()]];
                        result[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};