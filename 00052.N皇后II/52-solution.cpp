//同51，51求具体摆放方案，52求方案数
class Solution {
public:
    int res = 0;
    int totalNQueens(int n) {
        //用来判重
        vector<bool> col(n, 0);
        vector<bool> dig(2 * n + 1, 0);//对角线
        vector<bool> udig(2 * n + 1 , 0);//反对角线
        
        dfs(0, n, col, dig, udig);
        return res;
    }

    void dfs(int row, int n, vector<bool>& col, vector<bool>& dig, vector<bool>& udig) {
        if (row == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dig[i-row+n] && !udig[row+i]) {
                col[i] = dig[i-row+n] = udig[row+i] = 1;
                dfs(row + 1, n, col, dig, udig);
                col[i] = dig[i-row+n] = udig[row+i] = 0;
            }
        }
    }
};