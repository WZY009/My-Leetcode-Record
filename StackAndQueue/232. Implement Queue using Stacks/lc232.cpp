class MyQueue {
public:
    stack<int> in_stack;
    stack<int> out_stack;
    MyQueue() {

    }

    void push(int x) {
        this->in_stack.push(x); // pay attention! you can not push the node into out_stack directly! because it will disable the function of in_stack!
    }

    int pop() {
        if (this->out_stack.empty()) {
            while (!this->in_stack.empty()) {
                int temp = this->in_stack.top();
                this->in_stack.pop();
                this->out_stack.push(temp);
            }
        }
        int temp = out_stack.top();
        this->out_stack.pop();
        return temp;
    }

    int peek() {
        if (this->out_stack.empty()) {
            while (!this->in_stack.empty()) {
                int temp = this->in_stack.top();
                this->in_stack.pop();
                this->out_stack.push(temp);
            }
        }
        int temp = out_stack.top();
        return temp;

    }

    bool empty() {
        return this->in_stack.empty() && this->out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */