//直接旋转，第i行放置到第n - i - 1列，时空复杂度O(n^2)，需要使用额外空间O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> c = matrix;
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[j][m - i - 1] = c[i][j];
            }
        }
    }
};


//原地完成，时间复杂度O(n^2),空间复杂度为O(1)
//先转置矩阵，然后前后列交换（第1列和最后一列交换，第2列和倒数第2列交换...）
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //转置矩阵
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //前后交换列
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};