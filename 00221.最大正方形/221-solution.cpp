//动态规划自己做出来的，不容易:)
//定义状态dp[i][j]表示以点i,j为右下角正方形的面积
//位置（i, j）上的最大正方形的面积取决于三个部分，分别是dp[i-1][j-1],dp[i-1][j],dp[i][j-1]位置上的正方形的面积
//位置（i, j）上的正方形的边长是，上述这三个部分正方形边长的最小值+1。最后返回最大的面积即可
//时间复杂度O(m*n)，空间复杂度O(m*n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1'){
                    dp[i+1][j+1] = 1;
                    int min_s = min(dp[i][j], min(dp[i+1][j], dp[i][j+1]));
                    dp[i+1][j+1] = (sqrt(min_s) + 1) * (sqrt(min_s) + 1);
                    res = max(res, dp[i+1][j+1]);
                }
            }
        }
        return res;
    }
};