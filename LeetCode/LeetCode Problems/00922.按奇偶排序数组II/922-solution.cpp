//双指针，i，j分别指向偶数位和奇数位，如果i，j所指向的位满足条件，则i += 2, j += 2，直到遇到不符合的位置
//交换i，j不符合位置上的数，使得交换后两个位置的数都满足条件
//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 1;
        while (i < A.size() && j < A.size()) {
            while (i < A.size() && A[i] % 2 == 0) i += 2;//检查偶数位置上的数是否符合，当停下时，说明偶数位置上的数不符合
            while (j < A.size() && A[j] % 2 == 1) j += 2;//检查奇数位置上的数是否符合，当停下时，说明奇数位置上的数不符合
            if (i < A.size() && j < A.size()) swap(A[i], A[j]);//交换偶数和奇数位置上不符合的数，使得两个位置上的数都符合
        }
        return A;
    }
};