/*
dp: 定义状态f[i][j]表示从第i行第j列出发，能够安全到达终点的最低血量，考虑当前状态f[i][j]，可以到达哪些状态
向右走到达f[i][j + 1]，f[i][j] >= f[i][j + 1] - w[i][j]; 保证能够向右走的最低血量
向下走达到f[i + 1][j], f[i][j] >= f[i + 1][j] - w[i][j]; 保证能够向下走的最低血量
同时注意，每个格子的血量不能低于1，最后答案就是f[0][0]

时间复杂度O(m * n)，空间复杂度O(m * n)
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& w) {
        int m = w.size(), n = w[0].size();

        vector<vector<int>> f(m + 1, vector<int>(n + 1, 1e8));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) f[i][j] = max(1, 1 - w[i][j]);//初始化
                else {
                    if (j + 1 < n) f[i][j] = f[i][j + 1] - w[i][j];
                    if (i + 1 < m) f[i][j] = min(f[i][j], f[i + 1][j] - w[i][j]);
                    f[i][j] = max(1, f[i][j]);
                }
            }
        }
        return f[0][0];
    }
};