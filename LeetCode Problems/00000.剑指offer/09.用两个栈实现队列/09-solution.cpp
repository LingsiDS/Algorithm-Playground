class CQueue {
public:
    stack<int> stk1, stk2;
    CQueue() {

    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if (stk2.empty()) {
            if (stk1.empty()) return -1;
            while (stk1.size()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        auto t = stk2.top();
        stk2.pop();
        return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */