//二分查找，时间复杂度O(logn)
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x / 2 + 10;

        while (l < r) {
            long long mid = l + r + 1 >> 1;
            if (mid * mid <= x) l = mid;//使用long long防止溢出
            else r = mid - 1;
        }
        return l;//第一个小于sqrt(x)的整数
    }
};