//搜索，枚举每个子序列的长度，判断当前子序列是否是之前两个子序列的和，
//直到所有子序列都满足f[i] = f[i - 1] + f[i - 2];
class Solution {
public:
    bool f = false;
    vector<int> path;

    vector<int> splitIntoFibonacci(string S) {
        string last = "1", pre = "1";
        dfs(0, S, last, pre);
        return path;
    }

    void dfs(int pos, string &s, string &last, string &pre) {
        for (int l = (path.size() >= 2 ? last.size() : 1); pos + l <= s.size(); l++) {
            string sub = s.substr(pos, l);
            if ((sub[0] == '0' && sub.size() > 1)) continue;//不允许以0开头的数字
            long long sum = (long long)stoll(last) + stoll(pre);
            long long cur = (long long)stoll(sub);
            
            if (cur > INT_MAX || (path.size() > 2 && cur > sum)) return;//已经比之前的和都大或者cur超出了INT范围
            if (cur == sum || path.size() < 2) {
                path.push_back(cur);
                if (pos + l == s.size() && path.size() > 2) {//检查是否划分完成
                    f = true;
                    return;
                }
                dfs(pos + l, s, sub, last);
                if (f) return;
                path.pop_back();
            }
        }
    }
};