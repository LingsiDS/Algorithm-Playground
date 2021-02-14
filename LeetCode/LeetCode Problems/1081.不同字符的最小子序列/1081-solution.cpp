//思路同402题，单调栈，时间复杂度O(n)
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);

        for (int i = 0; i < s.size(); i++) {//统计每个字符出现的次数
            cnt[s[i] - 'a']++;
        }
       
        unordered_set<char> st; //记录一个字符是否已经作为答案使用过了
        string res;//单调栈
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']--;
            if (res.empty()) {
                st.insert(s[i]);
                res.push_back(s[i]);
            } else {
                if (st.count(s[i])) continue;//之前已经加入，说明s[i]在高位更加“合适”，也就是更小
                while (res.size() && res[res.size() - 1] > s[i] && cnt[res[res.size() - 1] - 'a'] > 0) {//保持单调递增栈，同时，保证字符串的每个不同元素必须包含
                    st.erase(res[res.size() - 1]);
                    res.pop_back();
                }
                res.push_back(s[i]);
                st.insert(s[i]);

            }
        }
        return res;
    }
};