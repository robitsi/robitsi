class MyQueue {
private:
    stack<int> inStack, outStack;

    void transferInToOut() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
public:
    MyQueue() {}
    void push(int x) {
        inStack.push(x);
    }
    int pop() {
        if (outStack.empty()) {
            transferInToOut();
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    int peek() {
        if (outStack.empty()) {
            transferInToOut();
        }
        return outStack.top();
    }
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
