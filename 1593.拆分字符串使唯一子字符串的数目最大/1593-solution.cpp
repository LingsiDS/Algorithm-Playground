class Solution {
public:
    unordered_map<string, int> hash;
    int res = 0;
    int maxUniqueSplit(string s) {
        dfs(s, 0, 0);
        return res;
    }

    void dfs(string& s, int idx, int sum) {
        if (idx >= s.size()) {
            res = max(res, sum);
            return;
        }

        //当前子字符串数sum + 剩余字符个数（s.size() - idx）比已经找到的结果res小，
        //则当前情况不可能将剩余字符串分割得比res大，return剪枝
        if (sum + s.size() - idx < res) return;
        for (int len = 1; len + idx <= s.size(); len++) {//枚举以idx为下标，len为长度的子串
            string substr = s.substr(idx, len);
            //为找到该字符，或者标记为0，则该字符还没被使用
            if (hash.find(substr) == hash.end() || hash[substr] == 0) {
                hash[substr] = 1;
                sum++;
                dfs(s, idx + len, sum);
                hash[substr] = 0;//回溯标记清零
                sum--;
            }
        }
    }
};