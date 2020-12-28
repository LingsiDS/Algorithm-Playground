//利用归并排序求逆序对经典题，时间复杂度O(nlogn)，空间复杂度O(logn)
class Solution {
public:
    int res = 0;
    vector<int> t;
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        t.resize(n, 0);
        merge(0, nums.size() - 1, nums);
        return res;
    }

    void merge(int l, int r, vector<int> &nums) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge(l, mid, nums);
        merge(mid + 1, r, nums);
        int i = l, j = mid + 1, idx = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) t[idx++] = nums[i++];
            else t[idx++] = nums[j++], res += mid - i + 1;
        }
        while (i <= mid) t[idx++] = nums[i++];
        while (j <= r) t[idx++] = nums[j++];
        for (int i = l, k = 0; i <= r; i++, k++)
            nums[i] = t[k];
    }
};