//方法一：双指正+栈模拟入栈顺序，遍历出栈序列，如果当前元素还没入栈，则将入栈序列到当前元素入栈，并将当前元素出栈；
//如果当前要出栈的元素已经在栈中，则一定在栈顶，否则该出栈序列非法
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), m = popped.size();
        if (!n && !m) return true;
        if (!n || !m || m != n) return false;

        unordered_map<int, int> numToIdx;
        for (int i = 0; i < pushed.size(); i++) numToIdx[pushed[i]] = i;

        stack<int> stk;
        int i = 0, j = 0;//双指针，[0, i - 1]的元素都已经入栈，j指向poped中正在出栈的元素
        while (j < m) {
            int first = numToIdx[popped[j]];
            if (first >= i) {//当前元素还没入栈
                for (int k = i; k <= first; k++) {//把当前元素以及，在当前元素之前的所有元素入栈
                    stk.push(k);
                    i++;
                }
                stk.pop();
            } else {//当前元素已经入栈了
                if (first != stk.top()) return false;//如果当前元素要出栈，必须在栈顶
                stk.pop();
            }
            j++;
        }
        return true;
    }
};

//简洁写法，遍历入栈序列，将入栈序列压栈，当要出栈的元素等于栈顶元素时，将栈顶元素出栈
//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0 && popped.size() == 0) return true;
        if (pushed.size() == 0 || popped.size() == 0 || pushed.size() != popped.size()) return false;
        stack<int> stk;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while (stk.size() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        return !stk.size();
    }
};