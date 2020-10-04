//时间复杂度为O(n!), 空间复杂度为O(n)
//使用回溯算法求解即可，关键点是如何对对角线（左上到右下）以及反对角线（右上到左下）进行判重
//以左上角为坐标原点，分别以x，y的增长方向为坐标轴建立坐标系，可以发现，对角线上的元素可以
//记为y = x + b, b = y - x,反对角线上的元素可以记为y = -x + b, b = y + x，根据数学知识可以知道
//位于同一条对角线/反对角线上的点，他们的截距都是相等的，利用这点来判断对角线和反对角线上的元素是否重复
class Solution {
public:

    vector<vector<string>> res;
    
    vector<vector<string>> solveNQueens(int n) {
        //用来判重
        vector<bool> col(n, 0);
        vector<bool> dig(2 * n + 1, 0);//对角线
        vector<bool> udig(2 * n + 1 , 0);//反对角线
        
        vector<string> path;
        string s(n, '.');
        for (int i = 0; i < n; i++) path.push_back(s);
        
        dfs(0, path, n, col, dig, udig);
        return res;
    }

    void dfs(int row, vector<string>& path, int n, vector<bool>& col, vector<bool>& dig, vector<bool>& udig) {
        if (row == n) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dig[i-row+n] && !udig[row+i]) {
                path[row][i] = 'Q';
                col[i] = dig[i-row+n] = udig[row+i] = 1;
                dfs(row + 1, path, n, col, dig, udig);
                path[row][i] = '.';
                col[i] = dig[i-row+n] = udig[row+i] = 0;
            }
        }
    }
};