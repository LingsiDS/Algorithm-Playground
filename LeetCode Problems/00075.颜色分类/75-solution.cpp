//时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size()-1; i <= k;) {
            if (nums[i] == 0) swap(nums[i++], nums[j++]);
            else if (nums[i] == 1) i++;
            else swap(nums[i], nums[k--]);
        }
    }
};