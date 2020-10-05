class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        //以下n >= 3   因为需要用到nums[0], nums[1], nums[2]，注意nums的下标从0开始
        vector<int> dp(n + 5, 0);   //rob nums[0 ~ n-2]     dp[i]表示抢劫第 0 ~ i家商店的所有可能方案的集合，属性为最大值
        vector<int> dp2(n + 5, 0);  //rob nums[1 ~ n-1]     dp2[i]表示抢劫第1 ~ i家商店的所有可能方案的集合，属性为最大值 

        //初始化
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        
        //dp
        for (int i = 3; i <= n-1; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]); //rob nums[0 ~ n-2]
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);//rob nums[1 ~ n-1]
        }
        
        return max(dp[n-1], dp2[n-1]);//dp[n-1] == rob the most money of nums[0 ~ n-2], dp2[n-1] == rob the most money of nums[1 ~ n-1]
    }
};


//空间优化版，空间复杂度O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        //以下n >= 3   因为需要用到nums[0], nums[1], nums[2]，注意nums的下标从0开始
        //vector<int> dp(n + 5, 0);   //rob nums[0 ~ n-2]     dp[i]表示抢劫第 0 ~ i家商店的所有可能方案的集合，属性为最大值
        //vector<int> dp2(n + 5, 0);  //rob nums[1 ~ n-1]     dp2[i]表示抢劫第1 ~ i家商店的所有可能方案的集合，属性为最大值 

        //初始化
        int ppre = nums[0];
        int pre = max(nums[0], nums[1]);
        int ppre2 = nums[1];
        int pre2 = max(nums[1], nums[2]);
        
        //dp
        for (int i = 3; i <= n-1; i++) {
            int t  = max(pre, ppre + nums[i-1]); //rob nums[0 ~ n-2]
            ppre = pre;
            pre = t;
            
            t = max(pre2, ppre2 + nums[i]);//rob nums[1 ~ n-1]
            ppre2 = pre2;
            pre2 = t;
        }
        
        return max(pre, pre2);//pre == rob the most money of nums[0 ~ n-2], pre2 == rob the most money of nums[1 ~ n-1]
    }
};