//时间复杂度O(n*target)，空间复杂度O(n*target)
//第一反应暴力搜索，看到数据范围会超时没尝试，最后看了官方题解思路转化为0-1背包问题
//假设整个数组和为totoal，首先两个子集和相等，则两个子集的和都为total/2
//然后表示状态dp[i][j]表示从[1, i]中选(防止下标越界从1开始，实际上nums下标从0开始，后续nums的下标减一即可)，和为j的方案是否存在，状态转移可以通过是否选择nums[i]分为两类
//不选择nums[j]:dp[i][j] = dp[i-1][j]，选择nums[i-1]（注意i从1开始，这里用nums[i-1]，同时j >= nums[i-1]保证下标不会越界）:dp[i][j] = dp[i-1][j-nums[i-1]]
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return false;
        int total = 0, maxVal = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            maxVal = max(maxVal, nums[i]);
        }
        int target = total / 2;
        if (total % 2 == 1 || maxVal > target) return false;//

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;//不选任何元素和为0，初始化为true
        }
        dp[1][nums[0]] = true;//从[1,1]中选，只有和为nums[0]或者0（和为0在上面考虑过了）的方案可能
        for (int i = 1; i <= n; i++) {//下标从1开始，防止判断越界
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-nums[i-1]]);
            }
        }
        return dp[n][target];
    }
};




//时间复杂度O(n*target)，空间复杂度O(target)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return false;
        int total = 0, maxVal = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            maxVal = max(maxVal, nums[i]);
        }
        int target = total / 2;
        if (total % 2 == 1 || maxVal > target) return false;

        vector<bool> dp(target + 1, 0);

        dp[nums[0]] = true;//从[1,1]中选，只有和为nums[0]或者0的方案可能
        dp[0] = true;
        for (int i = 2; i <= n; i++) {//初始化时考虑过[1,1],从[1,2]开始考虑
            for (int j = target; j >= nums[i-1]; j--) {//从大到小枚举
                dp[j] = max(dp[j], dp[j-nums[i-1]]);
            }
        }
        return dp[target];
    }
};