//动态规划经典例题，先假设字符串a，b下标从1开始，状态定义dp[i][j]：表示将a[1~i]变成b[1~j]的所有方式的集合，属性：最小操作次数
//a变成b有3种方式，第一种方式：增加，要使得增加后a[1~i]等于b[1~j]，可以在a[1~i]于b[1~j-1]匹配的情况下，在a最后增加b[j]即可
//所以这一步的转移为：dp[i][j] = dp[i][j-1] + 1; 第二种方式：删除，要使得删除后a[1~i-1]与b[1~j]匹配，删除a[i]即可，这一步的
//转移为：dp[i][j] = dp[i-1][j] + 1; 第三种方式：修改，如果a[1~i-1]已经和b[1~j-1]匹配，则只需要将a[i]修改为b[j]即可，但是
//要注意a[i]可能扥与b[j]，这样就不需要修改了，这一步的转移为:dp[i][j] = dp[i-1][j-1] + a[i] == b[j]

//确定完转移方程，考虑边界情况，为了方便dp的下标从1开始，dp下标为1对应字符串下标为0，这样的话dp[0][i]表示a为空串要转化成b[1~i]
//所需要的最小操作次数，最小操作次数就是增加i个字符，所以dp[0][i] = i; 同样dp[i][0]表示a[1~i]变成空串最少需要的操作次数，显然
//最少需要的操作次数就是删除a中i个字符dp[i][0] = i;

//时间复杂度O(n*m)，空间复杂度O(n*m)
class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        //dp[i][j]:将a[0~i]变成b[0~j]的最小操作次数
        vector<vector<int>> dp(n+2, vector<int>(m+2, 0));

        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) dp[0][i] = i;
        for (int i = 1; i <= n; i++) dp[i][0] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                if (a[i-1] == b[j-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                else dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
       
        return dp[n][m];
    }
};