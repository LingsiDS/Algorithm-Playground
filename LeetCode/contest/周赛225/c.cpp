class Solution {
public:
    int kthLargestValue(vector<vector<int>>& w, int k) {
        int m = w.size(), n = w[0].size();
        
        vector<int> t;
        vector<vector<int>> f(m + 1, vector<int>(n + 3, 0));
        for (int i = 1; i <= n; i++) {
            f[1][i] = f[1][i - 1] ^ w[0][i - 1];
            t.push_back(f[1][i]);
        }
        for (int i = 2; i <= m; i++) {
            f[i][1] = f[i - 1][1] ^ w[i - 1][0];
            t.push_back(f[i][1]);
        }
        
        
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                f[i][j] = f[i - 1][j] ^ f[i][j - 1] ^ f[i - 1][j - 1] ^ w[i - 1][j - 1];
                t.push_back(f[i][j]);
            }
        }
        sort(t.begin(), t.end(), [](int a, int b) {
            return a > b;
        });
        return t[k - 1];
    }
};
