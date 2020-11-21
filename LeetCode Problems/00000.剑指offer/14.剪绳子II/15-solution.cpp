//数学O(n/3)
class Solution {
public:
    const int mod = 1e9+7;
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        long long res = 1;
        while (n >= 5) {
            n -= 3;
            res = (res * 3) % mod;
        }
        return res * n % mod;
    }
};


//数学时间复杂度O(1)
class Solution {
public:
    const int mod = 1000000007;
    typedef unsigned long long ULL;
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        int num_of_three = n / 3;
        n = n % 3;
        if (n == 1) {//余下4，2*2 > 3*1
            num_of_three -= 1;
            n += 3;
        }
        return n ? ksm(3, num_of_three, mod) * n % mod : ksm(3, num_of_three, mod);W
    }

    ULL ksm(ULL a, ULL b, ULL p) {
        ULL res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % p;
            }
            b >>= 1;
            a = (a * a) % p;
        }
        return res;
    }