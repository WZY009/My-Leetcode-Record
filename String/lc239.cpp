// define a special queue
// good resources: https://www.youtube.com/watch?v=m-Dqu7csdJk&t=690s&ab_channel=GeeksforGeeks
// MyQueue is a decreasing queue.
class MyQueue {
public:
    deque<int> dq;
    void pop(int value) {
        if (!dq.empty() && value == dq.front()) {
            dq.pop_front();
        }
    }
    void push(int value) {
        while (!dq.empty() && value > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(value);
    }
    int front() {
        return dq.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue* myqueue = new MyQueue();
        vector<int> result;
        for (int i = 0; i < k; i++) {
            myqueue->push(nums[i]);
        }
        result.push_back(myqueue->front());
        for (int i = k; i < nums.size(); i++) { // i is the head pointer
            myqueue->pop(nums[i - k]);
            myqueue->push(nums[i]);
            result.push_back(myqueue->front());
        }
        return result;
    }
};
