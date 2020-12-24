//思路较为跳跃，本题可转化为求m和n的最长相同前缀。m和n从高位开始比较，当出现第一个不相同的位时，
//m为：xxx...xxx0...    n为：xxx...xxx1...，而因为[m, n]为连续区间，必然存在从
//xxx...xxx0111...111到xxx...xxx1000...000的变化过程，而这两个数相与的结果为其后所有不同数都为0

//时间复杂度O(logn)，空间复杂度O(1)

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            if ((m & (1 << i)) ^ (n & (1 << i))) {
                break;
            } else res |= m & (1 << i); 
        }
        return res;
    }
};