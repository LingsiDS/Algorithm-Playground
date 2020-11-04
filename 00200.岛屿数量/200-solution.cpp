//对每个陆地进行bfs搜索所有陆地，统计一共进行了多少次bfs即为答案。
//时间复杂度O(m*n)，空间复杂度O(m*n)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0;  j < grid[0].size(); j++) {
                if (grid[i][j] == '1') bfs(grid, i, j);
            }
        }
        return res;
    }

    int res = 0;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    void bfs(vector<vector<char>>& g, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        g[x][y] = '2';
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            x = p.first, y = p.second;
            //cout << x << " " << y << endl;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= g.size() || ny >= g[0].size() || g[nx][ny] != '1')continue;
                g[nx][ny] = '2';
                q.push({nx, ny});
            }
        }
        res++;
    }
};


//并查集实现，时空复杂度O(m*n)
class Solution {
public:
    vector<int> parent;
    int m, n;
    int res = 0;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y, int nx, int ny) {
        int rt = find(x * n + y), rt_new = find(nx * n + ny);
        if (rt != rt_new) {
            parent[rt] = rt_new;
            res--;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    res++;
                }
                else parent.push_back(-1);
            }
        }
        
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                            unite(i, j, nx, ny);
                        }
                    }
                }
            }
        }
        return res;
    }
};