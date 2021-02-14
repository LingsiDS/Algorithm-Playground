class Solution {
public:
    struct edge {
        int x, y, w;
    };
    vector<int> p;
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        p.resize(m * n + 5, 0);
        for (int i = 0; i < m * n + 2; i++) p[i] = i;

        vector<edge> edges;
        for (int i = 0; i < m; i++) {//将所有点格子看成一个点，相邻点直接有连边
            for (int j = 0; j < n; j++) {
                int num = i * n + j;
                if (j + 1 < n)
                    edges.push_back({i * n + j, i * n + j + 1, abs(heights[i][j] - heights[i][j + 1])});
                if (i + 1 < m) 
                    edges.push_back({i * n + j, (i + 1) * n + j, abs(heights[i][j] - heights[i + 1][j])});
            }
        }

        if (edges.empty()) return 0;

        sort(edges.begin(), edges.end(), [](auto &e1, auto &e2) {//所有边按权值排序
            return e1.w < e2.w;
        });
        

        int idx = 0;
        while (find(0) != find(m * n - 1)) {//每次选择一条耗费最小的边将两个点连接起来，直到左上角到右下角连通
            int a = edges[idx].x, b = edges[idx].y;
            p[find(a)] = find(b);
            idx++;
        }
        return edges[idx - 1].w;
    }
};