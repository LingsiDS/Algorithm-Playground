//埃氏筛法，时间复杂度为O(nloglogn),空间复杂度O(n)
class Solution {
public:
    const static int N = 5 * 10e6 + 10;
    bool is_prime[N];
    int countPrimes(int n) {
        if (n < 2) return 0;
        memset(is_prime, 1, sizeof is_prime);//默认把所有数设置为素数
        
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                res++;
                for (int j = 2 * i; j < n; j += i) {//把所有素数的倍数筛去
                    is_prime[j] = 0;
                }
            }
        }
        return res;
    }
};

//线性筛法，时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> is_prime(n + 1, 1);
        vector<int> primes;

        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
            }

            for (int j = 0; primes[j] * i < n; j++) {
                is_prime[i * primes[j]] = false;
                if (i % primes[j] == 0) break;
            }
        }
        return primes.size();
    }
};