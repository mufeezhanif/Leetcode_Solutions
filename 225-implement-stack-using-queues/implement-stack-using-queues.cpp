class MyStack {
public:
    queue<int> q1;
    MyStack() {}

    void push(int x) {
        q1.push(x);
        int size = q1.size();
        int i =0;
        while (i<size-1) {
            q1.push(q1.front());
            q1.pop();
            ++i;
        }
    }

    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() { return q1.front(); }

    bool empty() { return q1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */