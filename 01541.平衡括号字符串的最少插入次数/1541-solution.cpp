//使用栈匹配括号，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        if (s.size() == 0) return res;
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
            }
            else if (s[i] == ')') {
                if (stk.empty()) {
                    if (i + 1 < s.size() && s[i + 1] == ')') {
                        res++;//插入(
                        i++;
                    }
                    else res += 2;//前面插入(，后面插入)
                }
                else if (stk.top() == '(' && i + 1 < s.size() && s[i + 1] == ')') {//匹配
                    stk.pop();
                    i++;
                }
                else if (stk.top() == '(' && (i + 1 >= s.size() || s[i+1] != ')') ) {
                    res++;//插入一个)
                    stk.pop();
                }
            }
        }
        res += 2 * stk.size();
        return res;
    }
};

//因为栈中只会放入(，所以我们可以使用一个int记录左括号的数量代替栈，从而使空间复杂度变为O(1)
class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        if (s.size() == 0) return res;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;//push '('
            }
            else if (s[i] == ')') {
                if (!cnt) {
                    if (i + 1 < s.size() && s[i + 1] == ')') {
                        res++;//插入(
                        i++;
                    }
                    else res += 2;//前面插入(，后面插入)
                }
                else if (i + 1 < s.size() && s[i + 1] == ')') {//匹配
                    cnt--;
                    i++;
                }
                else if ((i + 1 >= s.size() || s[i+1] != ')') ) {
                    res++;//插入一个)
                    cnt--;
                }
            }
        }
        res += 2 * cnt;
        return res;
    }
};