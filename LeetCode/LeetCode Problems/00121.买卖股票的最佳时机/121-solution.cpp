//遍历数组，同时记录一个第i天之前的历史最低价格，尝试在第i天卖出股票，记录最大收益
//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;//记录到当前该天的股票的最低价格
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {//遍历数组
            if (prices[i] > min_price) res = max(res, prices[i] - min_price);//如果比最低价格还低，尝试卖出股票
            if (prices[i] < min_price) min_price = prices[i];//如果当前该天是最低价格，则更新最低价格
        }
        return res;
    }
};