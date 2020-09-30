//使用二进制的思想，最多需要循环31次，x / y = k, 如果有x / y >= 2^i，则k的第i位为1
class Solution {
public:
    int divide(int a, int b) {
        typedef long long ll;
        vector<ll> exp;
        for (int i = 0; i <= 31; i++) {//exp[i]=2^i
            exp.push_back(1ll << i);
        }
        bool minus = false;
        if (a < 0 && b > 0 || a > 0 && b < 0) minus = true;
        
        ll x = abs(ll(a)), y = abs(ll(b));
        ll res = 0;
        
        //  x / y = k, 如果有x / y >= 2^i，则k的第i位为1，i从大到小，每次比较x>=exp[i]，如果成功res += exp[i]
        for (int i = exp.size()-1; i >= 0; i--) {]
            if (x >= exp[i] * y) {
                x -= exp[i] * y;
                res += exp[i];
            }
            if (x == 0) break;
        }
        if (minus) res = -res;
        if (res < INT_MIN || res > INT_MAX) res = INT_MAX;
        return (int)res;
    }
};


//利用倍增思想，假设求a / b = k,每次找满足条件a >= b^k,的最大的k，被除数减去b*k,结果加上k
//而找上诉的条件可以使用倍增的思想，首先尝试b满足不，然后尝试b^1,b^2,b^3...
class Solution {
public:
    int divide(int a, int b) {
        typedef long long ll;
        if (a == INT_MIN && b == -1) return INT_MAX;

        bool minus = false;
        if (a < 0 && b > 0 || a > 0 && b < 0) minus = true;
        ll x = abs(ll(a)), y = abs(ll(b));

        ll res = 0;
        while (x >= y) {//x < y res = 0
            ll t = y, cnt = 1;//t为除数
            while (t + t <= x) {//找到小于被除数的最大的除数的倍数
                cnt += cnt;
                t = t + t;
            }
            x -= t;     //被除数减去除数的某个倍数
            res += cnt; //结果加上除数的倍数
        }
        if (minus) res = -res;
        return (int)res;
    }
};