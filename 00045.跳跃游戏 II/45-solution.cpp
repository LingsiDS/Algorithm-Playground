//dp 时空复杂度为O(n)
//f[i]表示从起点到i最少需要多少步，则答案为f[n-1]
//可以证明f[i]的值为不减小的序列，且每次增加只会增加1，可以使用反证法证明
//设f[i] > f[j],i<j,且有从某点k（k<i）可以跳到j使得从起点到j的最小位置为f[j] = f[k]+1
//则从k也一定可以跳到i,使得f[i] == f[j]，所以与假设，i<j,f[i]>f[j]矛盾

//所以我们可以以一段区间为单位更新f，假设当前可以跳到的区间为[start, end]，在该区间内找到
//最远可以到达的位置m(m<nums.size())，f[end+1, m] = f[start] + 1
//重复以上步骤直到f[n-1]被赋值即可，每个区间会被扫描2遍（查找最远距离，赋值），最多扫描2n次，时间复杂度为O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> f(n+1, 0);//f[i]表示从起点到i最少需要多少步

        int start = 0, end = 0;
        while (end < n - 1) {
            int m = -1;//最远可以跳到的下一个位置
            for (int i = start; i <= end; i++) {
                m = max(m, nums[i] + i);
            }
            for (int j = end + 1; j <= m && j < n; j++) {//为下一个区间赋值，下一个区间不能超过n
                f[j] = f[start] + 1;
            }
            start = end + 1;//更新区间
            end = m;
        }
        return f[n-1];
    }
};