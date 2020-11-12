//动态规划，参考https://www.acwing.com/solution/content/410/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size();

        //表示匹配key的第i个字符，且ring的第j个字符位于12点的位置
        vector<vector<int>> f(n, vector<int>(m, 0x3f3f3f3f));

        //初始化
        for (int i = 0; i < m; i++) {
            if (key[0] == ring[i])//key的第0个字母和ring的第i个字母匹配
                f[0][i] = min(i, m - i) + 1;//考虑顺时针旋转到i，或者逆时针旋转到i
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (key[i] == ring[j]) {
                    for (int k = 0; k < m; k++) {
                        f[i][j] = min(f[i][j], f[i-1][k] + min(abs(j - k), m - abs(j - k)) + 1);//考虑顺时针旋转到j，或者逆时针旋转到j
                    }
                }
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < m; i++)
            res = min(res, f[n - 1][i]);
        
        return res;
    }
};