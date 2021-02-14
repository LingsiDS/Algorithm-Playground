//dp，f[i]为爬到当前层所需的最小花费，可以使用2个变量优化，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pre = 0, cur = 0;
        pre = cost[0], cur = cost[1];
        int res = 0;
        for (int i = 2; i < cost.size(); i++) {
            res = min(pre, cur) + cost[i];
            pre = cur, cur = res;
        }
        return min(pre, cur);
    }
};