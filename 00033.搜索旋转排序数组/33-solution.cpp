//基本思路，首先使用二分法查找出两段有序数据的分界点，然后判断target在哪个分界点，再使用普通的二分即可，时间复杂度O(logn)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;

        //二分两段有序数的边界
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[0] <= nums[mid]) l = mid;
            else r = mid - 1;
        }//二分完成后，l==r是最后一个大于等于nums[0]的数的下标
        if (target < nums[0]) l = l + 1, r = nums.size() - 1;
        else l = 0;

        //二分查找target
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] == target) return l;//使用nums[r]，使用nums[l]可能会下标越界
        else return -1;
    }
};