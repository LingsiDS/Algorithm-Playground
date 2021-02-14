//递归、分治，递归式为T(n) = T(3n/4) + O(c)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        return find(0, m - 1, 0, n - 1, matrix, target);
    }

    //find在matrix[l1~r1, l2~r2]构成的矩形中找target，找到返回true，否则返回false
    bool find(int l1, int r1, int l2, int r2, vector<vector<int>> &matrix, int target) {
        //出界，返回false
        if (l1 > r1 || l2 > r2) return false;
        if (l1 < 0 || l2 < 0 || r1 >= matrix.size() || r2 >= matrix[0].size()) return false;
        
        int mid1 = (l1 + r1) / 2, mid2 = (l2 + r2) / 2;
        if (target == matrix[mid1][mid2]) return true; //找到返回true
        
        if (target < matrix[mid1][mid2]) {//target < matrix[mid1][mid2]，右下角矩形区域里的元素大于matrix[mid1][mid2]，target不可能在右下角，在排除右下角的区域里继续递归
            return find(l1, mid1 - 1, l2, r2, matrix, target) || find(mid1, r1, l2, mid2 - 1, matrix, target);
        } else {// target > matrix[mid1][mid2]，左上角矩形区域里的元素小于matrix[mid1][mid2]，target不可能在左上角，在排除了左上角的区域里继续递归
            return find(mid1 + 1, r1, l2, r2, matrix, target) || find(l1, mid1, mid2 + 1, r2, matrix, target);
        }
    }
};