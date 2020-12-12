//方法一：模拟+贪心，要使得翻转后的矩阵得分最大，经过以下3步即可
//1.通过行变换将第一列全部转换为1
//2.对于后面的每一列，如果该列0的个数多余1的个数，翻转
//3.计分
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int m = A.size(), n = A[0].size();

        //首先把第一列全部变换成1
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0)
                for (int j = 0; j < n; j++) A[i][j] = A[i][j] == 0 ? 1 : 0;
        }
        
        //考察每一列是否应该翻转
        for (int i = 1; i < n; i++) {//第i列
            int cnt_one = 0;
            for (int j = 0; j < m; j++) {//统计第i列1的个数
                if (A[j][i] == 1) cnt_one++;
            }
            if (cnt_one <= m / 2) {//1的个数少于一半
                for (int j = 0; j < m; j++) A[j][i] = A[j][i] == 0 ? 1 : 0;//第i列反转
            }
        }

        //计算翻转后的得分
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cnt_one = 0;
            for (int j = 0; j < m; j++) {
                if (A[j][i] == 1) cnt_one++;
            }
            res += cnt_one * pow(2, n - i - 1);
        }
        return res;
    }
};


//方法一的思路已经非常好了，但是可以不比修改原矩阵，直接计算得分
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int m = A.size(), n = A[0].size();
        int res = m * (1 << (n - 1));//最高位全部为1
        
        for (int j = 1; j < n; j++) {//从第二列开始考虑
            int cnt_one = 0;
            for (int i = 0; i < m; i++) {//统计1的个数
                if (A[i][0] == 1) cnt_one += A[i][j];
                else cnt_one += 1 - A[i][j];//如果该行已经翻转过，则A[i][j]真实值应该为1 - A[i][j];
            }
            int k = max(cnt_one, m - cnt_one);//1应该是较多的那个
            res += k * (1 << (n - j - 1));//计算第j列的得分
        }
        return res;
    }
};