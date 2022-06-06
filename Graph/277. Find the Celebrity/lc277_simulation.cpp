/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        stack<int> st;
        for(int i = 0; i < n; i++) st.push(i);
        while(st.size() > 1) {
            int p1 = st.top(); st.pop();
            int p2 = st.top(); st.pop();
            if(knows(p1, p2)) st.push(p2);
            else st.push(p1);
        }
        int cand = st.top(); st.pop();
        for(int i = 0; i < n; i++) {
            if(i == cand) continue;
            if(knows(cand, i) || !knows(i, cand))  return -1;
        }
        return cand;
    }
};