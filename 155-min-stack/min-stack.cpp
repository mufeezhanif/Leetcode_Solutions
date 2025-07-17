class MinStack {
public:
    stack<int> st, minst;

    MinStack() {}

    void push(int val) {
        st.push(val);
        if (!minst.empty() && minst.top() < val) {
            int min = minst.top();
            minst.pop();
            minst.push(val);
            minst.push(min);
        } else {
            minst.push(val);
        }
    }

    void pop() {
        int top = st.top();
        st.pop();
        if (minst.top() == top) {
            minst.pop();
        } else {
            int Top = minst.top();
            minst.pop();
            if (minst.top() == top) {
                minst.pop();
            }
            minst.push(Top);
        }
    }

    int top() { return st.top(); }

    int getMin() { return minst.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */