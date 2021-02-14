class Solution {
public:
    bool match(string& s, int i, string& p, int j) {
        if (s[i] == p[j]) return true;
        if (p[j] == '.') return true;
        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        s = ' ' + s;//前面加上空字符串，因为如果p开头就出现  某个字符+'*'则可以匹配空字符
        p = ' ' + p;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = 1;//空字符串可以匹配

        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {//j从1开始，因为任何字符串都不可能和空字符串匹配
                if (j + 1 <= n && p[j + 1] == '*') continue;//*必须和它前一个字母一起使用
                if (i > 0 && p[j] != '*') {
                    dp[i][j] = match(s, i, p, j) && dp[i - 1][j - 1];//s[i] == p[j] && dp[i-1][j-1]
                } else if (p[j] == '*') {
                    //dp[i][j] = dp[i][j-2] || f[i-1][j] && match(s[i], p[j-1]);
                    dp[i][j] = j-2 >= 0 && dp[i][j-2] || i-1 >= 0 && dp[i-1][j] && match(s, i, p, j - 1);
                }
            }
        }
        return dp[m][n];
    }
};