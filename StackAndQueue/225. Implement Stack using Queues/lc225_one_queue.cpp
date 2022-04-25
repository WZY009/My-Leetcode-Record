class MyStack {
public:
    queue<int> que;
    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int loop = que.size() - 1;
        for (int i = 0; i < loop; i++) {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        int result = que.front();
        que.pop();
        return result;
    }

    int top() {
        int loop = que.size() - 1;
        for (int i = 0; i < loop; i++) {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        int result = que.front();
        que.pop();
        que.push(result);
        return result;
    }

    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */