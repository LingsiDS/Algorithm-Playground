class Solution {
public:
    vector<int> p;
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    
    int m, n;
    
    //将每一个小方格分为两个部分，上半部分和下半部分，[x, y, f]，x，y表示单元格坐标，f=0表示上半部分，f=1表示下半部分
    int get_id(int x, int y, int f) {
        if (f == 0) {//up
            return x * n * 2 + y * 2;
        } else {//bottom
            return x * n * 2 + y * 2 + 1;
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        m = grid.size(), n = grid.size();
        int cnt = (m + 1) * (n + 1) * 2;
        p.resize(cnt + 10, 0);
        for (int i = 0; i < p.size(); i++) p[i] = i;//并查集初始化

        int res = m * n * 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cell_up = get_id(i, j, 0), cell_bottom = get_id(i, j, 1);//得到当前格子的上半部分和下半部分
                if (grid[i][j] == ' ') {//当前格子为空，将当前格子上下两部分合并
                    p[find(cell_bottom)] = find(cell_up);
                    res--;
                }
                int id = 0;
                if (i - 1 >= 0) {
                    id = get_id(i - 1, j, 1);
                    if (find(id) != find(cell_up)) {//合并当前格子的上半部分和上面格子的下半部分
                        p[find(id)] = find(cell_up);
                        res--;
                    }
                }
                if (j - 1 >= 0) {
                    if (grid[i][j - 1] == '/') {
                        id = get_id(i, j - 1, 1);        
                    }else id = get_id(i, j - 1, 0);
                    if (grid[i][j] == '\\') cell_up = cell_bottom;
                    if (find(id) != find(cell_up)) {//合并当前格子的左半部分和左边格子的右半部分
                        p[find(id)] = find(cell_up);
                        res--;
                    }
                }
            }
        }
        return res;
    }
};