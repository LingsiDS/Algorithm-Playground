//基数排序，时间复杂度为O(k*n)，n为数据个数，k为关键字个数，这里k为整数的位数
//空间复杂度O(n)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());//O(n)
        int exp = 1;

        vector<int> tmp(n, 0);
        
        while (maxVal >= exp) {
            vector<int> cnt(10, 0);
            for (int i = 0; i < nums.size(); i++) {//分配过程，但是不实际存放元素
                int pos = (nums[i] / exp) % 10;
                cnt[pos]++;
            }

            for (int i = 1; i < 10; i++) {//类似前缀和，cnt[i]表示基数为i的数前面有多少个数
                cnt[i] = cnt[i - 1] + cnt[i];
            }
            
            //收集过程
            for (int i = n - 1; i >= 0; i--) {//为保证排序的稳定性，此处循环i应从n到1，即当两元素关键字的值相同时，原先排在后面的元素在排序后仍应排在后面
                int pos = (nums[i] / exp) % 10;
                tmp[cnt[pos] - 1] = nums[i];//cnt[pos] - 1为在当前exp下，nums[i]在该躺排序后的位置
                cnt[pos]--;//已经使用过一个数
            }
            copy(tmp.begin(), tmp.end(), nums.begin());
            exp *= 10;
        }

        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};
