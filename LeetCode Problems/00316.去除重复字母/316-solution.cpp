//单调栈，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk;//单调栈

        vector<int> left(26, 0);//left记录每个字符剩下多少没有考虑
        vector<bool> st(26, 0);

        for (auto c: s) left[c - 'a']++;//left初始为记录字符串中所有字符出现的次数

        for (int i = 0; i < s.size(); i++) {//遍历字符串
            left[s[i] - 'a']--;
            if (st[s[i] - 'a']) continue;//s[i]已经在栈中，不重复入栈

            //如果当前s[i]比栈顶元素大，且栈顶元素还有剩余，那么将栈顶元素弹出，s[i]作为高位，会使得字典序更小
            while (stk.size() && stk[stk.size() - 1] > s[i] && left[stk[stk.size() - 1] - 'a'] > 0) {
                st[stk[stk.size() - 1] - 'a'] = false;
                stk.pop_back();
            }
            stk.push_back(s[i]);
            st[s[i] - 'a'] = true;//st[c]为true表示字符c在栈中
        }

        return stk;
    }
};