//dp，思路和62一样有障碍则当前路径无法到达，时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<int> f(n + 1, 0);    //状态
        if (g[0][0] == 1) return 0;//起点有障碍，则无法到达任何点

        for (int i = 1; i <= n; i++) //初始化状态
            if (!g[0][i-1]) f[i] = 1;
            else break;//如果有障碍，后续路径无法到达

        for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i-1][j-1]) f[j] = 0;
                else f[j] = f[j] + f[j-1];
            }
        }
        return f[n];
    }
};