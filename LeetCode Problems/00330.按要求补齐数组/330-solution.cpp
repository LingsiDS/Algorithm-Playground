/*
贪心算法
假设当前使用nums中的前i-1个数已经能够凑出[0, x)内的数，如果nums中还有数nums[i]，如果nums[i] <= x
那么加上nums[i]，能够凑出[0, x + nums[i])内连续的所有数，如果nums[i] > x，还没凑出[1, n]内的数
，那么加上nums[i]只能凑出[0, x)和[nums[i], nums[i] + x)两个不连续的区间，区间中间至少有x凑不出，此时我们必须加入额外的数字z，
要凑出x，加入的数字z <= x才对凑出x有帮助，另外我们应该使能够凑出的区间越大越好，贪心的选择z == x总能保证
凑出的区间越大，故此时每次选择z == x，能够连续凑出的区间扩大为[0, 2 * x + 1)；另外，如果nums中数字已用完，还没凑出[1, n]内的所有数字
则这种情况归为后一种情况，选择加入z == x
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long x = 1;//初始区间[0, 1）
        int res = 0, i = 0;
        while (x <= n) {
            if (i < nums.size() && nums[i] <= x) x += nums[i++];//第一种情况
            else {
                x += x; //第二种情况加入额外的数z == x
                res++;
            }
        }
        return res;
    }
};