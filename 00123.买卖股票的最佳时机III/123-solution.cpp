//123题是第121题的一个进阶版本，121题中只能进行一次交易，122题可以进行无数次交易，123题只能进行2次交易，都是求最大利润
//总体思路是这样：枚举分界点，在分界点之前进行第一次交易，在分界点包之后括分界点进行第二次交易，要使总利润最大只要两边利润最大即可
//分别求两边的最大利润思路同121题，设置一个记录数组f，f[i]表示从第[0, i]天只进行一笔交易获得的最大收益，利用121题的思路求解即可，
//第二笔交易从后往前枚举，记录最大价格maxp，枚举当前价格卖出，总价格最大为res = max(res, f[i-1] + maxp - prices[i])，i从n到0
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n, 0);//从第[0, i]天只进行一笔交易获得的最大收益

        for (int i = 0, minp = INT_MAX; i < n; i++) {
            f[i] = max(i - 1 >= 0 ? f[i - 1] : 0, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        

        int res = 0;
        for (int i = n - 1, maxp = prices[i]; i; i--) {
            res = max(res, (i - 1 >= 0 ? f[i - 1] : 0) + maxp - prices[i]);//前i-1天交易一次获得的最大利润加上第i天之后交易一次获得的最大利润
            maxp = max(maxp, prices[i]);
        }
        return max(res, f[n - 1]);//f[n-1]可能是只进行一笔交易
    }
};