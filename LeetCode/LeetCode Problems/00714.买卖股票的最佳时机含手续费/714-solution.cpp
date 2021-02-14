/*
贪心：假设第0 ~ i天之间的股票最低价格为p[minIdx], 最大价格为p[maxIdx]，且minIdx < maxIdx，什么时候应该卖出呢？
1.收益为正？如果当前收益为profit = p[maxIdx] - p[minIdx] - fee > 0 是否应该卖出？如果没有手续费的限制，我们只要收益为正
就卖出股票的策略是正确的。很容易想到，因为有手续费的存在，我们每次交易都必须“谨慎”，因为可能存在两次交易收益都为正，
但是如果将两次交易合并为一次交易，那么手续费只有一次，总收益可能更大。
2.那么什么时候进行一次交易是“安全”的呢？考虑这样两次交易，p1, p2, p3, p4，第一次交易为p2 - p1， 第二次交易为p4 - p3
如果p2 >= p3 + fee，那么交易是安全的。两次交易的总收益可以记作：profit = p2 - p1 - fee + p4 - p3 - fee
profit = p2 - p3 + p4 - p1 - 2 * fee, 且p2 - p3 = t >= fee,则有 p4 - p1 - fee + (t - fee)， 而t - fee >= 0，这样
可以看成分两次交易的收益至少与一次交易的收益一样，所以当p2 >= p3 + fee时，进行交易是安全的。

算法遍历数组一遍，时间复杂度O(n), 空间复杂度O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int res = 0;
        int minIdx = 0, maxIdx = 0;             //记录最小收益的下标，最大收益的下标。
        for (int i = 0; i < p.size(); i++) {    
            if (p[i] < p[minIdx]) minIdx = i;
            if (p[i] > p[maxIdx]) maxIdx = i;
            if (minIdx > maxIdx) maxIdx = minIdx;//保证maxIdx > minIdx
            if (minIdx < maxIdx && p[maxIdx] - p[minIdx] - fee > 0 && i + 1 < p.size() && p[maxIdx] - fee >= p[i + 1]) {//这样的交易是“安全”的
                res += max(0, p[maxIdx] - p[minIdx] - fee);
                minIdx = i + 1, maxIdx = i + 1;
            }
        }
        if (maxIdx < p.size() && minIdx < maxIdx) res += max(0, p[maxIdx] - p[minIdx] - fee);//如果最后收益为正，一定是安全的，进行交易
            
        return res;
    }
};