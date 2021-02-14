//时间复杂度O(logn)
class Solution {
public:
    double myPow(double x, int n) {
        double a = x;
        long long b = abs(n);//如果b是int，abs(INT_MIN)，b为INT_MIN，这样b右移的时候针对负数右移会造成无限循环
        double res = 1;
        while (b) {
            if (b & 1) res *= a;
            b >>= 1;
            a *= a;
        }
        if (n < 0) return 1 / res;
        else return res;
    }
};