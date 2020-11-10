//直接枚举“山脚”，找到一个山脚之后可以跳过，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.empty()) return 0;

        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            int j = i;
            while (j + 1 < A.size() && A[j] < A[j + 1]) j++;
            if (j == i) continue;
            int k = j;
            while (k + 1 < A.size() && A[k] > A[k + 1]) k++;
            if (j != i && k != j) {
                res = max(res, k - i + 1);
            }
            i = k-1;
        }
        return res;
    }
};