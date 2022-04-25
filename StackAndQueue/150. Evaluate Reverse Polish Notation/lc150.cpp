class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (isNum(tokens[i])) {
                st.push(stoi(tokens[i]));
            }
            else {
                int temp2 = st.top(); st.pop();
                int temp1 = st.top(); st.pop();
                int result = 0;
                switch (tokens[i][0]) { // Pay attention! string can not be used in switch sentence
                case '+':
                    result = temp1 + temp2;
                    break;
                case '-':
                    result = temp1 - temp2;
                    break;
                case '*':
                    result = temp1 * temp2;
                    break;
                case '/':
                    result = temp1 / temp2;
                    break;
                }
                st.push(result);
            }
        }
        return st.top();
    }
    bool isNum(string s) {
        if (s == "*" || s == "/" || s == "+" || s == "-") return false;
        else return true;
    }
};