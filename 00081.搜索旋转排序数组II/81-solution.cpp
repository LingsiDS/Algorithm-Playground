//数组中存在重复元素，二分边界点和第33题不同，不能直接二分边界，先去掉第二段数组中可能重复的数，
//这一步可能需要O(n)，下面代码第8行，二分出边界点之后在二分target，最坏时间复杂度为O(n)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int R = nums.size() - 1;
        while (R >= 0 && nums[R] == nums[0]) R--;//删掉第二段数组中重复的项，这样能保证第一段所有数大于等于nums[0]
        if (R < 0) return target == nums[0];

        int l = 0, r = R;
        while (l < r) {//二分边界点
            int mid = (l + r + 1) / 2;
            if (nums[0] <= nums[mid]) l = mid;
            else r = mid - 1;
        }

        if (target >= nums[0]) {//在第一段二分
            l = 0;
            r = r;
        }else {//在第二段二分
            l = r + 1;
            r = R;
        }

        while (l < r) {//二分target
            int mid = (l + r + 1) / 2;
            if (target >= nums[mid]) l = mid;
            else r = mid - 1;
        }
        return nums[r] == target;
    }
};