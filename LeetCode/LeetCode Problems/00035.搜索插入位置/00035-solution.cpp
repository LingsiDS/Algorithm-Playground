//二分模版题
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] < target) return l + 1;//可能插入的位置为末尾
        return l;
    }
};