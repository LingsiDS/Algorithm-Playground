//从右上角开始搜索，从右上角开始可以将在矩阵上的搜索过程转化为类似在二叉搜索树中进行，
//从右上角开始，左边的数都比当前元素小，下边的元素都比当前元素大，这样搜索路径的方向可以减少，
//如果当前元素matrix[i][j] == target则返回，如果matrix[i][j] > target则j--，如果matrix[i][j] < target，则i++

//时间复杂度O(n + m)，空间复杂度O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};