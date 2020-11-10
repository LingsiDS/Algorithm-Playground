//要找到一个新的排列比给定排列大，并且是比给定排列大的最小的一个
//首先如何找到比给定排列大的数呢？通过交换nums[i], nums[j], i < j, nums[i] < nums[j]即可
//但是我们要找比给定排列大的所有排列中的最小的，那么我们应该尽量保持高位不变，交换后面低位的数
//算法：从后往前比较一对数nums[i - 1] >= nums[i], 则i--，如果原序列完全是降序，那么反转整个序列
//否则，找到了nums[i - 1] < nums[i] 的数，这样才能把第i-1为换为更大的数从而获得更大的排列，要将
//i-1换为nums[i,...,n]中比nums[i]大的最小的数，这样才会使得新排列最小。交换完后，nums[i,...n]一定
//为降序，而要获得最小的排列，需要nums[i,...,n]反转为升序
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;

        //从后往前找到第一个升序对，这里可以保证该升序对后的数为降序排列
        int i = n - 1;
        while (i - 1 && nums[i - 1] >= nums[i]) i--;
        if (i - 1 == 0 && nums[i - 1] >= nums[i]) {//原排列所有元素都是降序，则反转为升序
            reverse(nums.begin(), nums.end());
            return;
        }

        int k = i, t = INT_MAX, idx = -1;
        while (k < n) {
            if (nums[k] > nums[i - 1]) {//找比nums[i - 1]大的最小的数
                if (nums[k] <= t) idx = k;//idx为比nums[i - 1]大的最小的数的下标
                t = min(t, nums[k]);//t为比nums[i - 1]大的最小的数
            }
            k++;
        }
        if (idx != -1) {
            swap(nums[idx], nums[i - 1]);//交换两个数
            reverse(nums.begin() + i, nums.end());//反转后序序列，使得它们升序排列
        }
    }
};