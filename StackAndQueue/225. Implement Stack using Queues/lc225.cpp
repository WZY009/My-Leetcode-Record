class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int loop = que1.size() - 1;
        for (int i = 0; i < loop; i++) {
            int temp = que1.front();
            que1.pop();
            que2.push(temp);
        }
        int result = que1.front();
        que1.pop();
        loop = que2.size();
        for (int i = 0; i < loop; i++) {
            int temp = que2.front();
            que2.pop();
            que1.push(temp);
        }
        return result;
    }

    int top() {
        int loop = que1.size() - 1;
        for (int i = 0; i < loop; i++) {
            int temp = que1.front();
            que1.pop();
            que2.push(temp);
        }
        int result = que1.front();
        que1.pop();
        loop = que2.size(); // pay attention! you can't just use uqe2.size() directly! because each loop the size of stack will reduce by one!
        for (int i = 0; i < loop; i++) {
            int temp = que2.front();
            que2.pop();
            que1.push(temp);
        }
        que1.push(result);
        return result;
    }

    bool empty() {
        return que1.empty();
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