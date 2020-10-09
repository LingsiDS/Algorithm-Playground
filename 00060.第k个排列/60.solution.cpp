//时间复杂度O(n^2), 空间复杂度O(n)
class Solution {
public:
    int get(int a) {//计算a的阶乘
        int res = 1;
        for (int i = 1; i <= a; i++) res *= i;
        return res;
    }
    string getPermutation(int n, int k) {
        string res(n, '0');
        vector<int> st(n+1, 0);//判重

        for (int i = 0; i < n; i++) {       //枚举res的第i位
            int f = get(n - i - 1);         //从[i+1, n)一共可以填f个数
            for (int j = 1; j <= n; j++) {  //枚举res[i]可能填的数是j
                if (st[j]) continue;
                if (f < k) k -= f;     //f<k该位不可能填j
                else {
                    res[i] = j +'0';   //该位填j
                    st[j] = true;
                    break;             //break尝试下一位
                }
            }
        }
        return res;
    }
};