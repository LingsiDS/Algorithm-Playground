class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {//最多执行32次
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res++;
            n = n & (n - 1);//将最后一个1反转为0
        }
        return res;
    }
};