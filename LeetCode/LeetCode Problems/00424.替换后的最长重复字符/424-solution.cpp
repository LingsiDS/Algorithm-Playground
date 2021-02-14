//滑动窗口，时间复杂度O(26 * n)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        
        int res = 0, cnt = k;
        for (char c = 'A'; c <= 'Z'; c++) {//枚举重复字母为c的最长子串长度
            cnt = k;//cnt表示队列中允许有多少与c不同的字符
            deque<char> dq;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c) dq.push_back(s[i]);
                else {
                    while (cnt == 0 && dq.size()) {
                        auto t = dq.front();
                        dq.pop_front();
                        if (t != c) cnt++;
                    }
                    dq.push_back(s[i]);
                    cnt--;
                    if (cnt < 0) dq.pop_front();//k = 0的特殊情况
                }
                res = max(res, (int)dq.size());
            }
        }
        return res;
    }
};