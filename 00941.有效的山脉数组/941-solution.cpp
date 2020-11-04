//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 1;
        while (i < A.size() && A[i] >= A[i-1]) i++;
        if (i == 1 || i == A.size()) return false;//没有递增序列，或者全是递增序列都是非法的
        while (i + 1 < A.size() && A[i] > A[i+1]) i++;
        if (i == A.size()-1) return true;//递减序列到达数组末尾则为true
        else return false;
    }
};