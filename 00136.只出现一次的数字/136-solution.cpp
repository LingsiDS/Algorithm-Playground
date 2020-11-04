//使用位运算，初始化一个int型数字res，将数组中所有元素与res进行异或运算
//所有出现2次的数字经过异或之后，它们的二进制表示位上一定为0，最后res就是出现一次的数字
//时间复杂度O(n)，空间复杂度O(1) :)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto a: nums) {
            res ^= a;
        }
        return res;
    }
};


//自己的思路，朴素方法：先遍历一遍数组，用哈希表存储每个元素出现的次数
//之后再遍历一次哈希表，找到出现次数为1的元素返回
//时间复杂度O(n)，空间复杂度O(n) :(
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto a: nums) hash[a]++;
        for (auto p: hash) {
            if (p.second == 1) return p.first;
        }
        return -1;
    }
};