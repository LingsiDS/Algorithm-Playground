//方法一：自己的第一直觉，因为要在常数时间内获得最小值，联想到小顶堆，又因为STL中堆不能删除指定的元素
//所以用vector手写一个堆，支持删除操作，删除操作需要在vector内查找到某元素再删除，时间复杂度O(n+logn)
//getMin()时间O(1)，删除O(n+logn)，另外实现堆需要额外O(n)的空间
class MinStack {
public:
    stack<int> stk;
    vector<int> heap;
    void up(int x) {
        int p = (x - 1) / 2;
        if (p >= 0) {
            if (heap[p] > heap[x]) {
                swap(heap[x], heap[p]);
                up(p);
            }
        }
    }
    
    void down(int x) {
        int l = 2 * x + 1, r = 2 * x + 2;
        int min_idx = x;
        if (l < heap.size() && heap[l] < heap[min_idx]) min_idx = l;
        if (r < heap.size() && heap[r] < heap[min_idx]) min_idx = r;
        if (min_idx != x) {
            swap(heap[x], heap[min_idx]);
            down(min_idx);
        }
    }

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        heap.push_back(x);
        up(heap.size()-1);
    }
    
    void pop() {
        auto p = find(heap.begin(), heap.end(), stk.top());
        int pos = p - heap.begin();
        stk.pop();
        swap(heap[pos], heap[heap.size()-1]);
        heap.pop_back();
        up(pos);
        down(pos);
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return heap[0];
    }
};


//方法二：使用两个栈，一个数据栈，保存数据，额外使用一个最小栈，保存栈中当前数据的最小值，数据栈是从栈底到栈顶
//非严格递减的（可相等），相当于在数据栈的一个非严格递减的子集，每次查找最小值只需要查看栈顶即可，另外数据栈出栈时，
//如果和最小栈顶数据相等，最小栈也同时出栈。
//时间复杂度，getMin()  O(1)，额外使用一个栈，最坏情况下数据栈就是递减的，则需要O(n)空间
class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x <= min_stk.top()) min_stk.push(x);
    }
    
    void pop() {
        if (stk.top() == min_stk.top()) min_stk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

//方法三：follow-up：额外空间O(1)   https://www.acwing.com/solution/content/6720/
//用一个min_value保存当前最小值，每次入栈，stack保存入栈数据与最小值的差，同时更新最小值
//出栈时，如果栈顶元素小于零，说明在这个元素入栈的时候，它是最小值，也就是现在的min_value
//这样我们需要还原出该元素出栈后的最小值，即为min_value_p，我们入栈时有：x - min_value_p = diff
//diff入栈，有我们之前的分析，当前元素时最小值，此时所以x是min_value，所以min_value_p = minvalue - diff，代码122行
//top操作类似，如果栈顶元素大于0，它不是最小值，返回其和最小值的和，否则它为最小值，这里需要特判栈中只有，代码127行
//1个元素的情况，栈空时我们直接放入的是x，不是差值。
class MinStack {
public:
    typedef long long LL;
    stack<LL> stk;
    LL min_value;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (stk.empty()) {
            stk.push(x);
            min_value = x;
        }
        else {
            stk.push(x - min_value);
            min_value = min(min_value, (LL)x);
        }
    }
    
    void pop() {
        if (stk.top() < 0) {//栈顶元素小于0，说明入栈时，该元素就比之前的min_value小，是一个新的最小元素
            min_value = min_value - stk.top();//恢复之前的最小元素
        }
        stk.pop();
    }
    
    int top() {
        if (stk.size() == 1) return stk.top();
        else if (stk.top() > 0)
            return stk.top() + min_value;
        else return min_value;//栈顶元素小于等于0，说明当前元素就是最小值
    }
    
    int getMin() {
        return min_value;
    }
};