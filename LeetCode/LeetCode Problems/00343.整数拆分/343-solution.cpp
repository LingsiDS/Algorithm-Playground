//记忆化递归，简单来说题意为找到m个整数，使得m个整数的和为n，并且m个整数的乘积最大
//定义状态f[n]表示整数n，拆分成至少两个整数，它们的和为n，并且它们的最大的乘积为f[n]
//对于长度为n的整数，至少划分为两段，假设划分的两段长度分别为l, n - l, 1 <= l < n，
//可以递归求解长度为l，和n - 1的子问题，同时这里会有很多重复计算，如果f[i]已经求出，不必再进行递归
class Solution {
public:
    int integerBreak(int n) {
        //因为至少要拆分为2个整数之和
        if (n == 2) return 1; //但是2不拆分比拆分更大，特殊处理一下
        if (n == 3) return 2;//3不拆分比拆分更大，特殊处理一下

        vector<int> f(n + 1, -1);//区间长为n，拆分成至少两个整数，最大的积
        f[0] = 1;
        f[1] = 1;//区间长度为1
        dfs(n, f);
        return f[n];
    }

    int dfs(int n, vector<int> &f) {
        if (f[n] != -1) return f[n]; //记忆化递归
        int res = n;//可以不拆分
        for (int l = 1; l < n; l++) {//将长度拆分为l, n - l 两段，1 <= l < n，注意l不能等于n，否则无限递归
            res = max(res, dfs(l, f) * dfs(n - l, f));//取最大的拆分方案
        }
        return f[n] = res;
    }
};