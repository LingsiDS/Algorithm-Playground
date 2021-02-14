//排序+并查集
class Solution {
public:
    vector<int> p;
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    struct edge {
        int x, y, w;
    };
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        p.resize(m * n, 0);
        for (int i = 0; i < p.size(); i++) 
            p[i] = i;
        
        vector<edge> edges;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                if (j + 1 < n)
                    edges.push_back({id, id + 1, max(grid[i][j], grid[i][j + 1])});
                if (i + 1 < m)
                    edges.push_back({id, id + n, max(grid[i][j], grid[i + 1][j])});
            }
        }

        if (edges.empty()) return 0;
        sort(edges.begin(), edges.end(), [](auto &e1, auto &e2) {
            return e1.w < e2.w;
        });

        int idx = 0;
        while (find(0) != find(m * n - 1)) {
            int ra = find(edges[idx].x), rb = find(edges[idx].y);
            p[ra] = rb;
            idx++;
        }
        return edges[idx - 1].w;
    }
};