//方法1：记忆化搜索
//时空复杂度O(n^3) ???，这题n最大为19
class Solution {
public:
    int res = 0;
    int mem[20][20][20];

    int numTrees(int n) {
        memset(mem, 0, sizeof mem);
        for (int i = 1; i <= n; i++) {
            unordered_map<int, int> hash;
            res += dfs(i, 1, n);
        }
        return res;
    }

    int dfs(int root, int l, int r) {//以root为根，可以使用的数为[l, r]，一共可以组成多少种二叉搜索树
        if (mem[root][l][r] != 0) return mem[root][l][r];//已经计算过，直接返回
        
        if (l >= r) {
            return 1;
        }
        int left = 0, right = 0;
        for (int i = l; i < root; i++) {//枚举左子树
            left += dfs(i, l, root-1);
        }

        for (int i = root+1; i <= r; i++) {//枚举右子树
            right += dfs(i, root+1, r);
        }

        if (left == 0 || right == 0) return mem[root][l][r] = (left ? left : right);//左右子树有一边为空，可以构成的BST的数目就是非空的那一边的数目
        else return mem[root][l][r] = left * right;//否则最终的方案数是左右子树方案数的乘积
    }
};

//递推，经过分析可以发现，二叉搜索树的数量只与区间的长度相关，如[1,10]和[2,11]能构成二叉搜索树的数量一样
//设f[i]表示长度为i的区间可以构成的二叉搜索树的数量，枚举根节点，设根节点为j，则长度为n的二叉搜索树的数量为
//sum(i = 1 to n)(f[i] += f[j-1]*f[i-j])
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {//求长度为i的区间能构成二叉搜索树的数目
            for (int j = 1; j <= i; j++) {//枚举根节点
                f[i] += f[j-1] * f[i-j];
            }
        }
        return f[n];
    }
};