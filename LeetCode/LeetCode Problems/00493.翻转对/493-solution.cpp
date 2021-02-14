//归并排序统计逆序对，和经典统计逆序对不同，这题统计逆序对需要使用双指针算法
//时间复杂度O(nlogn)，空间复杂度O(n)
class Solution {
public:
    int t[50010];
    int res = 0;
    int reversePairs(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        for (auto a: nums) cout << a << " " ; cout << endl;;
        return res;
    }

    void merge_sort(vector<int> &q, int l, int r) {
        if (l >= r) return ;
        int mid = (l + r) >> 1;

        merge_sort(q, l, mid);
        merge_sort(q, mid + 1, r);

        //双指针统计答案
        int x = l, y = mid + 1;
        while (x <= mid && y <= r) {
            if (q[x] > q[y] * 2ll) {
                res += mid - x + 1;
                y++;
            } else {
                x++;
            }
        }

        int i = l, j = mid + 1, idx = 0;
        while (i <= mid && j <= r) {
            if (q[i] <= q[j]) t[idx++] = q[i++];
            else t[idx++] = q[j++];
        }
        while (i <= mid) t[idx++] = q[i++];
        while (j <= r) t[idx++] = q[j++];

        for (int i = l, k = 0; i <= r; i++, k++) q[i] = t[k];
    }
};