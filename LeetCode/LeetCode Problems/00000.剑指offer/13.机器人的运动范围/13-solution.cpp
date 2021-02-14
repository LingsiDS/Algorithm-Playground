//bfs逐一将符合条件的点加入队列中
class Solution {
public:
    int movingCount(int m, int n, int k) {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        q.push({0, 0});
        vis[0][0] = 1;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        int res = 0;
        while (q.size()) {
            auto p = q.front();
            q.pop();
            res++;
            for (int d = 0; d < 4; d++) {
                int x = p.first + dx[d], y = p.second + dy[d];
                if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y] || !check(x, y, k)) continue;
                vis[x][y] = true;//在点加入队列时，应该标记为访问过，而不是在取出队列中的元素的时候判断，后者会有重复元素
                q.push({x, y});
            }
        }
        return res;
    }

    bool check(int x, int y, int k) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        if (sum <= k) return true;
        else return false;
    }
}; 