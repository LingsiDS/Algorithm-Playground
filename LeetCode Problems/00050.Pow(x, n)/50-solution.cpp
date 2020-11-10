//快速幂，时间复杂度为log(n)，空间复杂度O(1)
class Solution {
public:
    double myPow(double x, int n) {
        typedef long long ll;
        bool minus = false;
        if (n < 0) minus = true;
        double res = 1;
        ll k = abs(n);
        while (k) {
            if (k & 1) res = res * x;
            k = k >> 1;
            x = x * x;
        }
        if (minus) return 1 / res;
        return res;
    }
};

//朴素做法，时空复杂度O(n)
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0 ) return 1;
        if (n > 0)
            return x*pow(x, n-1);
        else return (1/x)*pow(x, n+1);
    }
};