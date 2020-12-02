//时间复杂度O(log(m + n))，参考题解：https://www.acwing.com/solution/content/50/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot & 1) {//奇数
            return find(nums1, 0, nums2, 0, tot / 2 + 1);
        } else {//偶数
            return (find(nums1, 0, nums2, 0, tot / 2) + find(nums1, 0, nums2, 0, tot / 2 + 1)) / 2.0;
        }
    }

    //在两个有序数组中找第k大的元素
    double find(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);//nums1的长度永远是两个数组中较小的
        if (nums1.size() == i) return nums2[j + k - 1];//nums1中所有数排除完，直接在nums2中找第k大的元素
        if (k == 1) return min(nums1[i], nums2[j]);//查找第一个元素，返回最小的即可
        int si = min(i + k / 2, (int)nums1.size()), sj = j + k / 2;//nums1和nums2的起始位置
        if (nums1[si - 1] <= nums2[sj - 1]){//nums1[0~si-1]不可能是第k大的元素
            return find(nums1, si, nums2, j, k - (si - i));
        } else {
            return find(nums1, i, nums2, sj, k - (sj - j));//nums2[0~sj-1]不可能是第k大的元素
        }
    }
};