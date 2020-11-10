//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;

        int i;
        for (i = 0; i < A.size(); i++) if (A[i] > 0) break;
        int j = i - 1;
        while (j >= 0 && i < A.size()) {
            if (abs(A[j]) < abs(A[i])) {
                res.push_back(A[j] * A[j]);
                j--;
            }
            else {
                res.push_back(A[i] * A[i]);
                i++;
            }
        }

        while (j >= 0 ) {
            res.push_back(A[j] * A[j]);
            j--;
        }

        while (i < A.size()) {
            res.push_back(A[i] * A[i]);
            i++;
        }

        return res;
    }
};