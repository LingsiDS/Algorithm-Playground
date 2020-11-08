//贪心：与第121题类似，在遍历数组的过程中，记录一个当前第i天之前的历史最低价格cur_min，并且假设在历史最低价格买入股票，
//当第i天的股票价格高于历史价格时，并且第i+1天的价格比第i天的价格更低，则选择卖出股票（这样操作能保证收益最大），因为此时如果后面有股票价格hight_price
//比当前第i天的价格更高，最坏我们也可以选择在第i+1天买入，并在最高价格时卖出获得利润：
//hight_price - prices[i + 1] + prices[i] - cur_min > hight_prece - cur_min

//简单来说，找出所有能够获得正向收益的交易，而所有在极值点卖出，并在极值点之前的历史最低价格买入的交易都是正向收益，该算法就是找出所有这种交易


//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = INT_MAX, res = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > cur_min && ((i + 1 < prices.size() && prices[i + 1] < prices[i]) || i + 1 >= prices.size())) {//极值点
                res += prices[i] - cur_min;//极值点卖出，极值点之前的历史最低价格买入
                cur_min = INT_MAX;
            }
            else if (prices[i] < cur_min) cur_min = prices[i];
        }

        return res;
    }
};

//另一种思路，从第i天买入，第j天卖出，同时第j天再买入，第k天卖出，等价于第i天买入，第j天卖出，根据这个性质，可知所有交易都可以分成天数间隔1的交易
//所以，所有prices[i+1] - prices[i] > 0的交易都能获得正向收益，记录下来即可，【计算的过程并不是实际的交易过程】，题意貌似不允许在第i天卖出再买入
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i + 1 < prices.size(); i++) 
            res += max(0, prices[i + 1] - prices[i]);
        return res;
    }
};