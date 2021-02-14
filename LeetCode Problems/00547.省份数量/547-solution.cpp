//方法一：并查集，并查集只是用路径压缩在平均情况下时间复杂度为很小的常数，但是最坏情况下时间复杂度为logn
//时间复杂度为O(n^2logn)，空间复杂度为O(n)
class Solution {
public:
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    int parent[201];
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) parent[i] = i;
        int res = n;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isConnected[i][j] == 0) continue;
                auto x = find(i), y = find(j);
                if (x != y) {   
                    res--;
                }
                parent[x] = y;
            }
        }
        return res;
    }
};

//BFS，时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        queue<int> q;
        int res = 0;
        for (int i = 0; i < n; i++) {//以点i为起点进行bfs
            if (visited[i]) continue;
            q.push(i);
            visited[i] = 1;
            while (q.size()) {
                auto t = q.front(); q.pop();
                for (int j = 0; j < n; j++) {
                    if (isConnected[t][j] == 1 && !visited[j]) {
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
            res++;//找到一个省份
        }
        return res;
    }
};