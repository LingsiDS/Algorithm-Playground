//空间最优解法
//首先记录第一行以及第一列是否包含0
//利用原矩阵，如果某一行出现0，将这一行的第一个元素置为0，如果某一列出现0，将这一列的第一个元素置为0
//然后再根据第一行，第一列将矩阵置零
//时间复杂度O(n*m)，空间复杂度为O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return ;
        int m = matrix.size(), n = matrix[0].size();

        int r = 1, c = 1;//如果第一行/第一列有0，相应变量置为0
        for (int i = 0; i < n; i++) if (!matrix[0][i]) r = 0;
        for (int i = 0; i < m; i++) if (!matrix[i][0]) c = 0;

        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                if (!matrix[i][j]) {//将第i行第j列置零的信息分别存储到该行/列的第一个元素中（因为该元素之后也会被清空，所以可以被覆盖）
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        
        for (int i = 1; i < m; i++) 
            if (!matrix[i][0])//第i行包含0
                for (int j = 1; j < n; j++) matrix[i][j] = 0;//将第i行置零
        
        for (int i = 1; i < n; i++)
            if (!matrix[0][i])//第i列包含0
                for (int j = 1; j < m; j++) matrix[j][i] = 0;//将第i列置零

        if (r == 0) for (int i = 0; i < n; i++) matrix[0][i] = 0;//第一行包含0，将第一行置零
        if (c == 0) for (int i = 0; i < m; i++) matrix[i][0] = 0;//第一列包含0，将第一列置零
    }
};



//朴素解法
//时间复杂度O(m*n)，额外空间O(m+n)，使用额外空间row[i] = 1表示第i行为0，col[j] = 1表示第j列为0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();

        vector<bool> col(m), row(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;//row[i] = 1表示第i行为0
                    col[j] = 1;//col[j] = 1表示第j列为0
                }
            }
        }

        for (int i = 0; i < n; i++) {//将所有行清零
            if (row[i] == 1) {
                for (int j = 0; j < m; j++) matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {//将所有列清零
            if (col[i] == 1) {
                for (int j = 0; j < n; j++) matrix[j][i] = 0;
            }
        }
    }
};



