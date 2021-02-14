//并查集，时间复杂度O(nlongn)
//对Alic和Blob分别维护2个并查集，同时先考虑第3类边即可。
class Solution {
public:
    vector<int> p1, p2;
    int find(int x, vector<int>& p) {
        if (p[x] == x) return x;
        return p[x] = find(p[x], p);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        p1.resize(n + 2, 0), p2.resize(n + 2, 0);
        for (int i = 0; i < n; i++) p1[i] = p2[i] = i;

        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] > b[0];
        });

        int res = 0, cnt = 0, cnt1 = 0, cnt2 = 0;
        for (auto &point: edges) {
            int ra, rb;
            if (point[0] == 3) {
                if (find(point[1], p1) != find(point[2], p1)) {
                    p1[find(point[1], p1)] = find(point[2], p1);
                    p2[find(point[1], p2)] = find(point[2], p2);
                    cnt++;
                } else res++;
            }
            if (point[0] == 2) {
                if (find(point[1], p2) != find(point[2], p2)) {
                    p2[find(point[1], p2)] = find(point[2], p2);
                    cnt2++;
                } else res++;
            }
            if (point[0] == 1) {
                if (find(point[1], p1) != find(point[2], p1)) {
                    p1[find(point[1], p1)] = find(point[2], p1);
                    cnt1++;
                } else res++;
            }
        }
        if (cnt1 + cnt == n - 1 && cnt2 + cnt == n - 1) return res;
        else return -1;
    }
};