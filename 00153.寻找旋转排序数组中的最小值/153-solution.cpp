//二分复杂度O(logn)，33题的子问题，本质为找到数组旋转的边界
//单调性为nums[mid] < nums[0]，找到数组中第一个比nums[0]小的位置即为最小元素
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        //数组本身有序，没有旋转
        if (nums[r] > nums[l]) return nums[0];
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[0] > nums[mid]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};