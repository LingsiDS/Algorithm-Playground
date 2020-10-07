//使用方向数组进行遍历，已经bool数组进行判重，时间复杂度O(m*n),空间复杂度O(m*n),这种方法便于思考以及实现
class Solution {
public:
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size(); 

        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        int cnt = m * n, direc = 0, x = 0, y = 0;
        while (cnt--) {
            res.push_back(matrix[x][y]);
            visited[x][y] = 1;
            int nx = x + dx[direc], ny = y + dy[direc];
            if (nx >= m || nx < 0 || ny < 0 || ny >= n || visited[nx][ny]) {
                direc = (direc + 1) % 4;
            }
            x += dx[direc];
            y += dy[direc];
        }
        return res;
    }
};


//分别遍历上下左右，空间复杂度O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();

        int cnt = m * n, top = 0, left = 0, right = n - 1, bottm = m - 1;
        vector<int> res;
        while (cnt >= 1) {
            for (int i = left; i <= right && cnt; i++) {
                res.push_back(matrix[top][i]);
                cnt--;
            }
            top++;

            for (int i = top; i <= bottm && cnt; i++) {
                res.push_back(matrix[i][right]);
                cnt--;
            }
            right--;

            for (int i = right; i >= left && cnt; i--) {
                res.push_back(matrix[bottm][i]);
                cnt--;
            }
            bottm--;
            
            for (int i = bottm; i >= top && cnt; i--) {
                res.push_back(matrix[i][left]);
                cnt--;
            }
            left++;
        }
        return res;
    }
};