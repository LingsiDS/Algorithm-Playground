//题型：状态机模型DP
//根据题意：[你必须在再次购买前出售掉之前的股票]，任意一天，有两种状态，没有股票，有股票还没出售
//定义两个状态：f[i][j]表示前i天，进行了j次交易后，当前没有股票的最大收益
//             g[i][j]表示前i天，进行了j次交易后，还有股票未出售的最大收益
//定义完成一次交易为从有股票的状态到无股票的状态，也就是从状态g转移到状态f
//状态转移方程为:f[i][j] = max(f[i-1][j], g[i-1][j-1] + prices[i])
//              g[i][j] = max(g[i-1][j], f[i-1][j] - prices[i])
//最后结果为：max(f[n][j]), n = prices.size(), 0<=j<=k
//初始状态：f[0][0] = 0，其余值初始化为负无穷，枚举时，下标i从1开始（减少边界判断），j从0开始（j=0表示没有进行交易其含义有意义不能忽略）
//时间复杂度O(n^2)，空间复杂度O(n^2)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        const int inf = 1e9;
        if (k >= n / 2) {
            int res = 0;
            for (int i = 0; i  + 1 < prices.size(); i++) {
                res += max(0, prices[i + 1] - prices[i]);
            }
            return res;
        }

        //f[i][j]表示前i天，进行了j次交易后，当前没有股票的最大收益
        vector<vector<int>> f(n + 1, vector<int>(k + 1, -inf));
        //g[i][j]表示前i天，进行了j次交易后，当前买入了股票的最大收益
        auto g = f;
        f[0][0] = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                f[i][j] = f[i-1][j];
                if (j-1 >= 0)
                    f[i][j] = max(f[i][j], g[i-1][j-1] + prices[i - 1]);//不变，卖出
                g[i][j] = max(g[i-1][j], f[i-1][j] - prices[i-1]);//不变，买入
                res = max(res, f[i][j]);
            }
        }
        return res;
    }
};


//空间优化版：因为当前状态的值只和i-1或者j-1的状态有关，可以优化成滚动数组
//优化方法，将动态规划状态的第一维定义为2，在所有使用到第一维的地方进行 [&1] 操作，其含义为对2取模
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        const int inf = 1e9;
        if (k >= n / 2) {
            int res = 0;
            for (int i = 0; i  + 1 < prices.size(); i++) {
                res += max(0, prices[i + 1] - prices[i]);
            }
            return res;
        }

        //f[i][j]表示前i天，进行了j次交易后，当前没有股票的最大收益
        vector<vector<int>> f(2, vector<int>(k + 1, -inf));
        //g[i][j]表示前i天，进行了j次交易后，当前买入了股票的最大收益
        auto g = f;
        f[0][0] = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                f[i & 1][j] = f[i-1 & 1][j];
                if (j-1 >= 0)
                    f[i & 1][j] = max(f[i & 1][j], g[i-1 & 1][j-1] + prices[i - 1]);//不变，卖出
                g[i & 1][j] = max(g[i-1 & 1][j], f[i-1 & 1][j] - prices[i-1]);//不变，买入
                res = max(res, f[i & 1][j]);
            }
        }
        return res;
    }
};