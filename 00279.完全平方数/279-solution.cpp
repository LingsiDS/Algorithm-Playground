//方法一：动态规划
//时间复杂度O(n*sqrt(n))，空间复杂度O(n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);//定义dp[i]表示i可以表示为多少个完全平方数的和
        f[0] = 0;
        for (int i = 1; i <= n; i++) {//枚举计算dp[i]的值
            for (int j = 1; j * j <= i; j++) {//当j*j <= i时，i至少可以分解为两个数i-j*j和j*j
                f[i] = min(f[i], f[i-j*j] + 1);//取所有可以分解的最少分解方案
            }
        }
        return f[n];
    }
};

//方法二：BFS
//和动态规划类似，建立一个数组f[i]记录i能够分解为完全平方数的最少个数
//从0开始，如果从该数加上一个完全平方数能够到达一个新的数，则将这两个数看做图上的两个点，
//能够到达则说明两个点直接有有向边，最先到达点n的方案需要的完全平方数最少。
//时间复杂度O(n*sqrt(n))，空间复杂度O(n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, 10000);//初始化为一个大数
        queue<int> q;
        q.push(0);
        f[0] = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p == n) break;
            for (int i = 1; p + i * i <= n; i++) {//枚举所有可以满足关系可以“到达”的点
                if (f[p + i * i] > f[p] + 1) {//更新，记录最小距离
                    f[p + i * i] = f[p] + 1;
                    q.push(p + i * i);
                }
            }
        }
        return f[n];
    }
};