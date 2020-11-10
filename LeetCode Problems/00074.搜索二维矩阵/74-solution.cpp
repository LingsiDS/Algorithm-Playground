//二分，时间复杂度为log(n)，空间复杂度O(1)
//朴素思想是先二分出target应该在的行，再在该行二分target应该在的列
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
 
        int l = 0, r = m - 1;
        while (l < r) {//查找元素应该在哪一行
            int mid = l + r + 1 >> 1;
            if (matrix[mid][0] <= target) l = mid;
            else r = mid - 1;
        }
        
        if (target > matrix[l][n-1]) return false;//该行最大的元素都比target小，target一定不在矩阵中

        int row = l;//记录target应该在的行
        l = 0, r = n - 1;
        while (l < r) {//二分查找target在第row行的哪一列
            int mid = l + r + 1 >> 1;
            if (matrix[row][mid] <= target) l = mid;
            else r = mid - 1;
        }
        if (matrix[row][l] == target) return true;
        else return false;
    }
};

//代码更短的写法，把整个数组当做一维数组进行二分时间复杂度O(logm*n)
//将一维数组的下标除以列大小得到二维数组的行坐标，对一维数组下标对列大小取余得到二维数组的列坐标
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
 
        int l = 0, r = m*n-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (matrix[mid / n][mid % n] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[l / n][l % n] == target;
    }
};