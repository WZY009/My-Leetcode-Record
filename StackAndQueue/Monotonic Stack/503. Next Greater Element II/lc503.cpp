class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result (nums.size(), -1);
        stack<int> st;
        st.push(0);
        for(int i = 1; i < nums.size() * 2; i++) {
            while(!st.empty() && nums[i % nums.size()] > nums[st.top() % nums.size()]) {
                result[st.top() % nums.size()] = nums[i % nums.size()];
                st.pop();
            }    
            st.push(i);
        }
        return result;
    }
};