//时间复杂度O(n)，空间复杂度为O(1)
class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 2;
        if (n == 1) return first;
        if (n == 2) return second;
        int res = 0;
        for (int i = 3; i <= n; i++) {
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
};