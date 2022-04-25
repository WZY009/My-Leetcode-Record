class Solution {
public:
    int fib(int n) {
        stack<int> st;
        st.push(n);
        int result = 0;
        while(!st.empty()) {
            int temp = st.top(); st.pop();
            if(temp == 1) result++;
            else if(temp == 0) continue;
            else {
                st.push(temp - 1);
                st.push(temp - 2);
            }
        }
        return result;
    }
};
