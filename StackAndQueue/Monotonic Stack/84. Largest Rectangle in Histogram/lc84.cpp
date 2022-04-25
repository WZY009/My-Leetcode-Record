// https://www.youtube.com/watch?v=RVIh0snn4Qc&t=848s&ab_channel=IrfanBaqui
// pay attention to the difference between the video and the code! especially the calculation order!

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0); // pay attention! you have to insert 0 at the start and end of the array or [2, 1, 3] will go worng!
        heights.push_back(0);
        st.push(0);
        int result = 0;
        
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) {
                st.push(i);
            } else if (heights[i] == heights[st.top()]) {
                st.pop(); 
                st.push(i);
            } else {
                while (heights[i] < heights[st.top()]) { 
                    int mid = st.top();
                    st.pop();
                    int left = st.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[mid];
                    result = max(result, w * h); // pay attention! it starts from the highest histogram and traverse from right to left!
                }
                 st.push(i);
            }
        }
        return result;
    }
};