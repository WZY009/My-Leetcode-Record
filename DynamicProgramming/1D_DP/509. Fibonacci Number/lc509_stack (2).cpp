class Solution {
public:
    int fib(int n) {
        std::stack<int, std::vector<int>> st;
        //stack<int> st; // don't use this one!
        st.push(n);
        int result = 0;
        int temp = 0;
        while(!st.empty()) {
            temp = st.top(); st.pop();
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
