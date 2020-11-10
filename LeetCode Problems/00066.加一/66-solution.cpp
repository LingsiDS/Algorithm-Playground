//扫描数组，模拟加法即可时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;//c表示进位
        int n = digits.size();
        if (!n) return {1};//边界情况
        c = (digits[n-1] + 1) / 10;//c先于digits更新
        digits[n-1] = (digits[n-1] + 1) % 10;
        int idx = n - 2;
        while (c && idx >= 0) {
            int t = digits[idx];
            digits[idx] = (digits[idx] + c) % 10;//这里注意digits要用到c
            c = (t + c) / 10;//c更新又要用到digits，这里先备份了digits
            idx--;
        }
        if (c) digits.insert(digits.begin(), 1);
        return digits;
    }
};