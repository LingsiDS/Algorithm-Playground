//dp, 时空复杂度为O(nm)
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s;//状态转移方程中下标有减一的部分，可以先插入一个空串避免特判
        p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, 0));//状态f[i][j] 表示s[0-i]与p[0-j]是否匹配

        f[0][0] = 1;//初始状态，空串可以匹配
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j] == '*') {//如果是通配符
                    f[i][j] = f[i][j - 1] || i && f[i - 1][j];//*可以匹配0个字符串，或者1,2,3...个字符串
                }
                else {//普通字符或者p[j] == '?'
                    f[i][j] = (s[i] == p[j] || p[j] == '?') && i && f[i - 1][j - 1];
                }
            }
        }
        return f[n][m];
    }
};