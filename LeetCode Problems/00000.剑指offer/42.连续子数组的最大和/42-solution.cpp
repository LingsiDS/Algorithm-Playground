//经典题，dp，时间复杂度O(n)，也可以使用分治法求解
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int pre = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur = max(nums[i], pre + nums[i]);
            res = max(res, cur);
            pre = cur;
        }   
        return res;
    }
};