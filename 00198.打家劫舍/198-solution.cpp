//动态规划时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n+3, 0);         //dp[i]表示偷取前i个房间能偷取的所有方案,属性偷取的最大金额
        dp[1] = nums[0];                //边界情况,初始化
        dp[2] = max(nums[0], nums[1]);
        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);//不偷第i个房间,偷第i个房间
        }
        return dp[n];
    }
};


//动态规划，时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        //vector<int> dp(n+3, 0);         	//空间优化，不需要额外的数组
        int first = nums[0];                //first = nums[0]
        int second = max(nums[0], nums[1]);	//second = nums[1]
        for (int i = 3; i <= n; i++) {
            int t = max(second, first + nums[i-1]);//dp[i-1] = second, dp[i-2] = first
            first = second;
            second = t;
        }
        return max(first, second);//最大金额为最后一个房间偷或者不偷所获得金额中较大的那个
    }
};