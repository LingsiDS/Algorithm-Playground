//方法一：dfs，对岛屿进行dfs，每个岛屿有4条边，然后减去陆地之间相邻的边即可
//时间复杂度O(m*n)，空间复杂度O(m*n)（使用了visited判重，也可以在grid原地判重，空间则为常数）
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    dfs(i, j, res, visited, grid);
                }
            }
        }
        return res;
    }

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    void dfs(int x, int y, int &sum, vector<vector<int>> &visited, vector<vector<int>> &grid) {
        visited[x][y] = 1;
        sum += 4;//每个正方形有4条边
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= visited.size() || ny >= visited[0].size() || !grid[nx][ny]) {
                continue;
            } 
            cnt++;//计算重复的边数，与已经访问过的格子的邻边也要计算
            if (visited[nx][ny]) continue;
            dfs(nx, ny, sum, visited, grid);
        }
        sum = sum - cnt;//用每个正方形的4条边减去重复的边
    }
};


//迭代的方法，对于每个陆地，边数先加上4，然后判断当前陆地的右方以及下方是否是陆地，如果每发现有一边是陆地边数就应减去2
//时间复杂度O(n*m)，空间复杂度O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res += 4;//每个陆地格子有4条边
                    if (j + 1 < n && grid[i][j + 1]) res -= 2;//如果当前陆地与右边陆地相邻，边数减去2
                    if (i + 1 < m && grid[i + 1][j]) res -= 2;//如果当前陆地与下方陆地相邻，边数减去2
                }
            }
        }
        return res;
    }
};