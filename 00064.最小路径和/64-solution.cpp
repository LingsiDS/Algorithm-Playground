//dp，求最小值/最大值，注意边界情况影响最大最小值，时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<int> f(n+1, 0);

        for (int i = 1; i <= n; i++) {
            f[i] = f[i-1] + grid[0][i-1];
        }


        for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[j] = f[j];
                if (j - 1 >= 1) f[j] = min(f[j], f[j-1]);//初始化所有状态为0，求最小值，注意边界
                f[j] += grid[i-1][j-1];
            }
        }
        return f[n];
    }
};