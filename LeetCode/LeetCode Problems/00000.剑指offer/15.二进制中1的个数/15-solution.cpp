//最多比较32次
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            if (n & 1) res++;
            n >>= 1;
        }
        return res;
    }
};

//n中有多少个1则执行多少次
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res++;
            n = n & (n - 1);//每次将二进制中最右边的一位1反转
        }
        return res;
    }
};