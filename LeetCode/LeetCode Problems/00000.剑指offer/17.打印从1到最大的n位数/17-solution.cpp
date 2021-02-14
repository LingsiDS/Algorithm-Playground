//不考虑大数的情况下
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        long long m = pow(10, n);
        for (int i = 1; i < m; i++) {
            res.push_back(i);
        }
        return res;
    }
};

//考虑大数，比如当n等于50时，一共有50位数，long long也存不下，只能使用字符串表示
//同时生成这些数的时候需要使用生成全排列的方法，时间复杂度为O(10^n)
class Solution {
public:
    vector<string> res;
    int N;
    vector<string> printNumbers(int n) {
        N = n;
        string path;
        dfs(1, path);
        return res;
    }
    void dfs(int x, string &path) {
        if (x == N + 1) {//x
            if (path.empty()) res.push_back("0");
            else res.push_back(path);
            return;
        }
        for (char i = '0'; i <= '9'; i++) {
            bool insert = true;//默认要插入
            if (i == '0' && path.empty()) insert = false;//前导0不加入
            if (insert) path += i;
            dfs(x + 1, path);
            if (insert) path.pop_back();
        }
    }
};