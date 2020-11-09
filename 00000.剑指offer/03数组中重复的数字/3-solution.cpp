class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        bool a[100010] = {0};//数组模拟哈希表
        for (int i = 0; i < nums.size(); i++) {
            if (a[nums[i]]) return nums[i];
            else a[nums[i]] = 1;
        }
        return -1;
    }
};