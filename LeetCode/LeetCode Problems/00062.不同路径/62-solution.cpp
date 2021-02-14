//简单dp，时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) dp[1][i] = 1;
        for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};


//空间复杂度优化为O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n+1, 0);
        for (int i = 1; i <= n; i++) f[i] = 1;
        for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[j] = f[j] + f[j-1];
            }
        }
        return f[n];
    }
};