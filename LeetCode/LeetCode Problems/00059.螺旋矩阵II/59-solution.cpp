//时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        int cnt = n * n;

        int num = 1, d = 0, x = 0, y = 0;
        while (cnt--) {
            visited[x][y] = 1;
            res[x][y] = num++;
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
                d = (d + 1) % 4;//改变方向
            }
            x = x + dx[d], y = y + dy[d];
        }
        return res;
    }
};