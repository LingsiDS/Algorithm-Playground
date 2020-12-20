//只用一个栈外加一个变量保存最小值，时间O(1)，空间O(n)
class MinStack {
public:
    typedef long long LL;
    stack<LL> stk;
    LL minV = 0;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (stk.empty()) {
            stk.push(x);
            minV = x;
        } else {
            stk.push(x - minV);
            minV = ::min(minV, (LL)x);
        }
    }
    
    void pop() {
        if (stk.top() < 0) {
            minV = minV - stk.top();
        }
        stk.pop();
    }
    
    int top() {
        if (stk.size() == 1) return stk.top();
        else if (stk.top() < 0) return minV;
        else return stk.top() + minV;
    }
    
    int min() {
        return minV;
    }
};


//使用一个辅助栈，保存当前的最小值
class MinStack {
public:
    stack<int> stk;
    stack<int> help; //非严格单调递减栈，栈顶元素为当前的最小值
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
        if (help.empty() || help.top() >= x) help.push(x);
    }
    
    void pop() {
        if (stk.top() == help.top()) help.pop();//当前出栈的为最小值，辅助栈也要出栈
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return help.top();
    }
};