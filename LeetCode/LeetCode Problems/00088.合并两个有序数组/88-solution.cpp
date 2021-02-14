//时间复杂度O(m + n)空间，复杂度O(m + n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> t;
        //cout << nums1.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) t.push_back(nums1[i++]);
            else if (nums1[i] > nums2[j]) t.push_back(nums2[j++]);
        }
        while (i < m) t.push_back(nums1[i++]);
        while (j < n) t.push_back(nums2[j++]);
        for (int i = 0; i < t.size(); i++) nums1[i] = t[i];
    }
};

//时间复杂度O(n+m)，空间复杂度O(1)，从后往前放置元素，先在nums1后面放置元素较大的
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int idx = nums1.size() - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) nums1[idx--] = nums1[i--];
            else nums1[idx--] = nums2[j--];
        }
        while (i >= 0) nums1[idx--] = nums1[i--];
        while (j >= 0) nums1[idx--] = nums2[j--];
    }
};