/*
图论，时间复杂度O(n * n)，空间复杂度O(n)
根据方程之间的关系建立图，求解方程的过程转化为图的遍历
*/
class Solution {
public:
    unordered_map<string, int> hash;
    int idx = 0, f = 0;
    vector<double> res;
    int st[41];
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<vector<double>> g(41, vector<double>(41, 0));
        for (int i = 0; i < equations.size(); i++) {//根据方程构建图
            string a = equations[i][0], b = equations[i][1];
            int x, y;
            if (hash.count(a)) x = hash[a];
            else {
                x = idx;
                hash[a] = idx++;
            }
            if (hash.count(b)) y = hash[b];
            else {
                y = idx;
                hash[b] = idx++;
            }
            g[x][y] = values[i];
            g[y][x] = 1.0 / values[i];
        }

        for (int i = 0; i < queries.size(); i++) {//遍历每个查询
            int x = hash.count(queries[i][0]) ? hash[queries[i][0]] : -1;
            int y = hash.count(queries[i][1]) ? hash[queries[i][1]] : -1;
            if (x == -1 || y == -1) {
                res.push_back(-1);
                continue;
            }
            f = 0;
            dfs(x, y, g, 1);//查询x到y是否右边，即方程是否可解
            if (!f) res.push_back(-1);
        }
        return res;
    }
    void dfs(int x, int y, vector<vector<double>> &g, double sum) {
        if (f) return;
        if (x == y) {
            f = 1;
            res.push_back(sum);
            return;
        }
        st[x] = 1;
        for (int i = 0; i < 41; i++) {
            if (g[x][i] == 0 || st[i]) continue;
            sum *= g[x][i];
            dfs(i, y, g, sum);
            sum = sum * 1.0 / g[x][i];
        }
        st[x] = 0;
    }
};