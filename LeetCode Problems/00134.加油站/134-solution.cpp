//贪心一次遍历，时间复杂度O(n)，空间复杂度O(1)
//枚举起点i，然后枚举从i能走的最远位置j，如果能够走完则返回i即可，否则表明从i不可以走到j
//可以证明，任意一个位于i，j之间的起点k，k也不能走到起点j，因为从i能走到j，则从i必然能够走到
//k，此时剩余的油量必然是大于等于0，而从k作为起点油量则从0开始，而油量大于等于0都不能走到j
//则以k为起点必然不能走到j。所以枚举下一个起点时，可以从j + 1开始枚举，只会遍历一遍，时间O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0, l; i < n;) {
            int left = 0;
            for (l = 0; l < n; l++) {//这里l是从i能够走的最远的长度
                int k = (i + l) % n; //从i走长度为l的距离的位置
                left += gas[k] - cost[k];
                if (left < 0) break; 
            }
            if (l == n) return i;
            i = i + l + 1; //从下一个位置开始枚举
        }
        return -1;
    }
};