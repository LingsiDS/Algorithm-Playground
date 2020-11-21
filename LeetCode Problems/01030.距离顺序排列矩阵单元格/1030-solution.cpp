//BFS，求点r0,c0出发的所有点的曼哈顿距离，时间复杂度O(R*C)
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        vector<vector<int>> res;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(R, vector<bool>(C, 0));

        q.push({r0, c0});
        visited[r0][c0] = true;
        res.push_back({r0, c0});
        
        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                auto x = t.first + dx[i], y = t.second + dy[i];
                if (x < 0 || x >= R || y < 0 || y >= C || visited[x][y]) continue;
                visited[x][y] = true;
                q.push({x, y});
                res.push_back({x, y});
            }
        }

        return res;
    }
};