//方法一：记忆化递归，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> f;//f[i]为第i个小朋友分到的糖果
    int n;

    int candy(vector<int>& ratings) {
        n = ratings.size();
        f.resize(n, -1);
        int res = 0;

        for (int i = 0; i < n; i++) res += dp(i, ratings);
        dp(0, ratings);
        for (auto a: f) cout << a << endl;
        return res;
    }

    int dp(int x, const vector<int> &w) {
        if (f[x] != -1) return f[x];
        f[x] = 1;
        if (x - 1 >= 0 && w[x] > w[x - 1]) f[x] = max(f[x], dp(x - 1, w) + 1);
        if (x + 1 < n && w[x] > w[x + 1]) f[x] = max(f[x], dp(x + 1, w) + 1);
        return f[x];
    }
};


//两次扫描，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> left(n, 0);
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;//分值大的多分糖果
            } else left[i] = 1;//至少分一个糖果
        }
        
        int res = 0;
        vector<int> right(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 <= n - 1 && ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else right[i] = 1;
            res += max(left[i], right[i]);
        }
        return res;
    }
};