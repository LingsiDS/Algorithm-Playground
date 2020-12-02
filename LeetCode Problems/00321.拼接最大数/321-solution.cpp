//贪心，算法正确性难易理解
//代码参考：https://www.acwing.com/solution/content/347/
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res(k);
        for (int i = max(0, k - m); i <= min(k, n); i++) {
            auto a = maxArray(nums1, i);
            auto b = maxArray(nums2, k - i);
            auto c = merge(a, b);
            res = max(res, c);
        }
        return res;
    }
    
    //合并两个子数组，使得合并后的子数组最大
    vector<int> merge(deque<int> &a, deque<int> &b) {
        vector<int> c;
        while (a.size() && b.size()) {
            if (a > b) {
                c.push_back(a[0]);
                a.erase(a.begin());
            } else {
                c.push_back(b[0]);
                b.erase(b.begin());
            }
        }
        while (a.size()) c.push_back(a[0]), a.erase(a.begin());
        while (b.size()) c.push_back(b[0]), b.erase(b.begin());
        return c;
    }

    //从num中选择k个元素的子序列，使得它们最大
    deque<int> maxArray(vector<int> &num, int k) {
        vector<int> res;
        if (k == 0) return {};
        int remain = num.size() - k;//可以删除remain个，最后剩下k个
        for (int i = 0; i < num.size(); i++) {
            while (res.size() && res[res.size() - 1] < num[i] && remain) {
                remain--;
                res.pop_back();
            }
            res.push_back(num[i]);
        }
        deque<int> ret;
        for (int i = 0; i < k; i++) ret.push_back(res[i]);//有可能删除的元素数量不到remain个，手动选择k个
        return ret;
    }
};