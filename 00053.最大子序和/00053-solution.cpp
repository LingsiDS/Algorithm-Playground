//遍历一遍求最大子序和，时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            //如果cur=cur+nums[i]比nums[i]还小,说明以i为起点的连续子区间的和一定会更大,将cur更新为nums[i]
            if (cur + nums[i] < nums[i]) cur = 0;
            cur += nums[i];
            res = max(res, cur);
        }
        return res;
    }
};


//分治法求解，时间复杂度O(n),空间复杂度O(logn)
class Solution {
public:
    struct Node{
    	//递归过程中需要维护以下信息
        int sum, s, ls, rs;//sum:本区区间所有元素的和，s:本区间的最大字序和，ls:本区间的最大前缀和，rs:本区间的最大后缀和
    };

    Node build(vector<int>& nums, int l, int r) {
        if (l == r) {
            return {nums[l], nums[l], nums[l], nums[l]};
        }

        int mid = l + r >> 1;
        Node ll = build(nums, l, mid), rr = build(nums, mid+1, r);
        Node res;
        res.sum = ll.sum + rr.sum;						//本区间所有元素和 = 左右区间所有元素之和
        res.s = max(max(ll.s, rr.s), ll.rs + rr.ls);	//最大连续子区间 = max(左右子区间最大连续子区间，或者左子区间最大后缀+右子区间最大前缀)
        res.ls = max(ll.ls, ll.sum + rr.ls);			//最大前缀 = max(左子区间最大前缀，左子区间所有元素和+右子区间最大前缀)
        res.rs = max(rr.rs, rr.sum + ll.rs);			//最大后缀 = max(右子区间最大后缀，右子区间所有元素和+左子区间最大后缀)
        return res;
    }

    int maxSubArray(vector<int>& nums) {
        auto a = build(nums, 0, nums.size()-1);
        return a.s;
    }
};