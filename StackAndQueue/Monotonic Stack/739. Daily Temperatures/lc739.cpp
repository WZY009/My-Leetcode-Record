class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.size() == 1) return vector<int>(1, 0);
        vector<int> result(temperatures.size(), 0);
        stack<int> st;
        st.push(0);
        for(int i = 1; i < temperatures.size(); i++) {
            if(temperatures[i] <= temperatures[st.top()]) {
                st.push(i);
            }
            else {
                while(!st.empty()) {
                    if(temperatures[i] <= temperatures[st.top()]) {
                        st.push(i);
                        break;
                    }
                    result[st.top()] = i - st.top();
                    st.pop();                                           
                }
                st.push(i);                
            }
        }
        return result;
            
    }
};