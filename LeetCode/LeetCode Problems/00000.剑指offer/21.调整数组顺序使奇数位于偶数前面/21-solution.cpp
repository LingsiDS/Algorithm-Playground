//时间复杂度O(n)，空间O(1)
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int idx = 0;//idx 记录奇数应该在的位置
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) swap(nums[idx++], nums[i]);//遇到i为奇数，则将i交换到idx的位置上
        }
        return nums;
    }
};