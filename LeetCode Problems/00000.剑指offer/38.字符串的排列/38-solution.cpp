//对于有重复元素，产生所有不重复的排列
//时间复杂度O(n!)
class Solution {
public:
    int n;
    vector<bool> used;
    vector<string> res;
    vector<string> permutation(string s) {
        n = s.size();
        used.resize(n, 0);
        string path;
        dfs(0, s, path);
        return res;
    }

    
    void dfs(int idx, string &s, string &path) {//idx表示正在搜索path的第idx个数
        if (idx >= n) {
            res.push_back(path);
            return ;
        }
        vector<bool> st(26, 0);
        for (int i = 0; i < n; i++) {
            if (st[s[i] - 'a'] || used[i]) continue;//不允许重复，剪枝
            st[s[i] - 'a'] = true;//第idx个数不允许重复
            used[i] = true;//已经使用过的数不再使用
            path += s[i];
            dfs(idx + 1, s, path);
            used[i] = false;
            path.pop_back();
        }
    }
};

//第二种剪枝方法
class Solution {
public:
    vector<string> res;
    int n;
    vector<bool> used;
    vector<string> permutation(string s) {
        n = s.size();
        used.resize(n, 0);
        sort(s.begin(), s.end());//先排序
        string path;
        dfs(0, s, path);
        return res;
    }

    void dfs(int idx, string &s, string &path) {
        if (idx >= n) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            used[i] = true;
            path += s[i];
            dfs(idx + 1, s, path);
            path.pop_back();
            used[i] = false;
            while (i + 1 < n && s[i] == s[i + 1]) i++;//同一个idx，跳过多个重复的s[i]
        }
    }
};