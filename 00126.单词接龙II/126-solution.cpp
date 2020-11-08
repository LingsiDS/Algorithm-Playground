//将每个字符串看做图上的一个节点，从该节点能够转换到的节点建立一条无向边，从起点bfs求到终点的距离
//使用一个哈希表dist存储每个节点到起点的最短距离，最后再从最后一个节点往前dfs搜索出所有最短路径，
//搜索最短路径时需要剪枝，只有dist[s] + 1 == dist[t]的路径才需要搜索，其中s是从t变换过来的字符串
//时间复杂度O(26*n*l^2 + 2^n*n*l)，前一项是bfs的时间复杂度，后一项是dfs搜索方案的时间复杂度，
//因为总方案是指数级别的，所以最坏情况下时间复杂度是指数级别，空间复杂度O(n)
//参考题解：https://www.acwing.com/solution/content/217/
class Solution {
public:
    unordered_set<string> hash;
    unordered_map<string, int> dist;//dist[s]，存储从其实字符串到字符串s的最短距离
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (auto s: wordList) hash.insert(s);
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            string t = s;
            for (int i = 0; i < s.size(); i++) {
                s = t;
                for (int c = 'a'; c <= 'z'; c++) {//求最短路，如果当前字符串s能够变换到一个新的字符串，说明这两个字符串之间存在边
                    if (c == s[i]) continue;
                    s[i] = c;
                    if (hash.count(s) && dist.count(s) == 0) {//注意这里判断dist数组是否被计算过，防止重复计算
                        dist[s] = dist[t] + 1;
                        if (s == endWord) break;
                        q.push(s);
                    }
                }
            }
        }
        path.push_back(endWord);
        dfs(endWord, beginWord);
        return res;
    }


    void dfs(string endWord, string &beginWord) {
        if (endWord == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        }
        else {
            string t = endWord;
            for (int i = 0; i < endWord.size(); i++) {
                endWord = t;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (endWord[i] == c) continue;
                    endWord[i] = c;
                    cout << endWord << endl;
                    if (dist.count(endWord) && dist[endWord] + 1 == dist[t]) {//第一个判断不能用hash，因为beginWord可能不在其中
                        path.push_back(endWord);
                        dfs(endWord, beginWord);
                        path.pop_back();
                    }
                }
            }
        }
    }

};
