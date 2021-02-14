//利用哈希表+堆，时间复杂度O(nlogn)，思路参考官方题解：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/solution/fen-ge-shu-zu-wei-lian-xu-zi-xu-lie-by-l-lbs5/
//思路：遍历数组nums，如果之前又以nums[i] - 1结尾的子序列，则nums[i]加入到以nums[i] - 1结尾且长度最短的子序列中，这样尽可能使得所有子序列长度大于3
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hash;

        for (auto k: nums) {
            if (hash.count(k - 1) == 0) {
                hash[k].push(1);
            } else {
                auto mlen = hash[k - 1].top();
                hash[k - 1].pop();
                if (hash[k - 1].size() == 0) hash.erase(k - 1);
                hash[k].push(mlen + 1);
            } 
        }
        for (auto it: hash) {
            auto pq = it.second;
            while (pq.size()) {
                auto l = pq.top();
                if (l < 3) return false;
                pq.pop();
            }
        }
        return true;
    }
};


//贪心，时间复杂度O(1), 空间复杂度O(1)，参考题解：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/solution/tan-xin-o1-kong-jian-fu-za-du-de-zui-you-jie-fa-by/
//关键思想：有cnt个nums[start]，应该先考虑添加到长度为1，2的子序列后，若还有剩余则添加到长度为3的子序列后
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        //dp1,dp2,dp3分别为以当前遍历点结尾，能够构造长度为1，2，大于等于3的子序列的长度
        int dp1 = 0, dp2 = 0, dp3 = 0;

        int i = 0;
        while (i < nums.size()) {
            int start = i;
            int k = nums[start], cnt = 0;
            while (i < nums.size() && nums[i] == k) i++, cnt++;//统计同一个数出现的次数

            if (start > 0 && nums[start] != nums[start - 1] + 1) {//不连续
                if (dp1 + dp2 > 0) return false;
                dp1 = cnt;
                dp2 = dp3 = 0;
            } else {
                if (dp1 + dp2 > cnt) return false;//cnt个nums[start]也不够将dp1个长度为1以及dp2个长度为2的子序列填满为长度为3
                int left = cnt - dp1 - dp2;//尽可能先满足长度较小的子序列
                int keep = min(left, dp3);//能够使多少dp3增加
                dp3 = dp2 + keep;//这些子序列以nums[start]结尾，长度大于等于3
                dp2 = dp1;
                dp1 = left - keep;//如果left将dp3增长后，还有剩余，此时必须开启新的子序列
            }
        }
        if (dp1 == 0 && dp2 == 0) return true;
        else return false;
    }
};